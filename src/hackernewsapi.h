/*
  The MIT License (MIT)

  Copyright (c) 2015 Andrea Scarpino <me@andreascarpino.it>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#ifndef HACKERNEWSAPI_H
#define HACKERNEWSAPI_H

#include <QObject>
#include <QVariantMap>

class QNetworkReply;
class QNetworkAccessManager;

class HackerNewsAPI : public QObject
{
    Q_OBJECT
public:
    explicit HackerNewsAPI(QObject *parent = 0);
    virtual ~HackerNewsAPI();

    void getItem(const int id);
    void getNewStories();
    void getTopStories();

Q_SIGNALS:
    void itemFetched(QVariantMap item);
    void multipleStoriesFetched(QVariantList ids);

protected Q_SLOTS:
    void onGetItemResult();
    void onMultipleStoriesResult();

private:
    QNetworkAccessManager* network;
};

#endif // HACKERNEWSAPI_H
