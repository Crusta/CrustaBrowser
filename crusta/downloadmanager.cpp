/* ============================================================
* Crusta - Qt5 webengine browser
* Copyright (C) 2017 Anmol Gautam <tarptaeya@gmail.com>
*
* THIS FILE IS A PART OF CRUSTA
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */

#include "downloadmanager.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QTreeWidget>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QTreeWidgetItem>
#include <QDir>
#include <QIcon>

void DownloadManager::createManager(){
    setLayout(vbox);
}

void DownloadManager::createHeader(){
    QStringList labels;
    labels.push_back("title");
    labels.push_back("address");
    labels.push_back("time");
    treeview->setColumnCount(3);
    treeview->setHeaderLabels(labels);
}