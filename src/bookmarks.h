#pragma once

#include <QComboBox>
#include <QDomDocument>
#include <QIcon>
#include <QLineEdit>
#include <QObject>
#include <QToolButton>
#include <QTreeWidget>
#include <QWidget>

struct BookmarkItem
{
    QString title;
    QString address;
    QString description;
    QString folder = QStringLiteral("general");
};

class BookmarkTreeItem : public QTreeWidgetItem
{
public:
    BookmarkItem bookmarkItem;
};

class Bookmarks : public QObject
{
    Q_OBJECT
public:
    explicit Bookmarks(QObject *parent = nullptr);

    QWidget *bookmarksWidget();

    static BookmarkItem isBookmarked(const QString &url);
    static void insertBookmark(const BookmarkItem &item);
    static void removeBookmark(const QString &url);
    static QWidget *popupWidget(const BookmarkItem &item);

Q_SIGNALS:
    void newTabRequested(const QUrl &url);

private:
    static QDomDocument s_xmlDom;
    static QMap<QString, BookmarkItem> s_bookmarks;

    QWidget *m_widget = nullptr;
    QTreeWidget *m_treeWidget = nullptr;

    static void readBookmarksFile();
    static void saveBookmarksFile();

    static void removeBookmarkFromXMLDom(const QString &url);

    void refreshBookmarksWidget();
    QTreeWidgetItem *xmlDomTraverse(QDomNode node);
};
