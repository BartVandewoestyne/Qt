#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>
#include <QFileInfo>
#include <QFileSystemWatcher>

#include <thread>

// Important remarks:
//
//   * When testing with Notepad++ (7.9.1), keep in mind that Notepad++ sometimes saves the file twice.
//     The first time, it sometimes saves with size 0 and sometimes with the correct size.
//     The second save is always with the correct size.
//
//   * Testing with
//
//       D:\>echo "fdfdsqfdsfdsqfdsfs" > test.txt
//
//     seems to work consistent and correct.
//
//   * Note that with gedit and vim, there might be trouble:
//
//       https://bugreports.qt.io/browse/QTBUG-53607
//       https://bugreports.qt.io/browse/QTBUG-46431
//       https://bugreports.qt.io/browse/QTBUG-24898
//       https://bugreports.qt.io/browse/QTBUG-46483
//       https://stackoverflow.com/questions/11669179/qt-qfilesystemwatcher-on-windows
//
//     In general, if the program you are using to save the file first creates a
//     temporary file somewhere else and then replaces the one we're watching,
//     it's not the same file anymore 
//
//     Possible workaround:
//       If the file is removed from the list of watched files, but a file with the same name still exists,
//       then the file was replaced and needs to be added back to the list. Another approach is to use the parent directory
//       to get notified about added/removed files and then update the list of watched files as needed.

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QStringList pathsToWatch{ "D:/test", "D:/test/test.txt" };
    QFileSystemWatcher watcher;
    const auto pathsThatCannotBeWatched = watcher.addPaths(pathsToWatch);
    for (const auto& path : pathsThatCannotBeWatched)
    {
        qDebug() << "Could not watch " << path << "!";
    }
    
    //QObject::connect(&watcher, &QFileSystemWatcher::directoryChanged, [&watcher](const QString& path) {
    //    qInfo() << "Directory " << path << " was changed at " << QDateTime::currentDateTime().toString();
    //    qInfo() << "=> list of watched directories: " << watcher.directories().join(" ");
    //    });

    QObject::connect(&watcher, &QFileSystemWatcher::fileChanged, [&watcher](const QString& file) {
        QFileInfo fileInfo(file);
        qInfo() << "File " << file << " was changed at " << QDateTime::currentDateTime().toString()
            << "and now has size " << QString::number(fileInfo.size());

        // WORKAROUND FOR EDITORS THAT REMOVE AND REPLACE THE FILE
        // See https://stackoverflow.com/questions/18300376/qt-qfilesystemwatcher-signal-filechanged-gets-emited-only-once
        // wait until the file exists again
        while (!fileInfo.exists())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        // Re-add the file, because some editors remove it...
        const auto added = watcher.addPath(file);
        if (!added)
        {
            qDebug() << "Could not re-add file to watchlist!";
        }
        qInfo() << "After re-adding, file " << file << " is has now size " << QString::number(fileInfo.size());
        // END WORKAROUND

        qInfo() << "=> list of watched files: " << watcher.files().join(" ");
        });

    return app.exec();
}
