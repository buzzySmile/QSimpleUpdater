/*
 * (C) Copyright 2014 Alex Spataru
 * (C) Copyright 2016 Alex Makarov
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 */

#ifndef DOWNLOADDIALOG_H
#define DOWNLOADDIALOG_H

#include <QWidget>

class QSslError;
class QNetworkReply;
class QNetworkAccessManager;

namespace Ui {
    class DownloadDialog;
}

class DownloadDialog : public QWidget
{
    Q_OBJECT

public:
    explicit DownloadDialog(QWidget *parent = 0);
    ~DownloadDialog();

    void beginDownload(const QUrl& url);

signals:
    void cancelDownload();

private slots:
    void onCancelDownload();
    void onDownloadFinished(QNetworkReply* pReply);
    void onDownloadProgress(qint64 received, qint64 total);
    void onIgnoreSslErrors(QNetworkReply *reply, const QList<QSslError>& error);

private:
    Ui::DownloadDialog *ui;

    bool isDownloadFinished;
    QNetworkAccessManager *m_manager;

    uint m_start_time;
    float roundNumber(const float& input);
};

#endif  // DOWNLOADDIALOG_H
