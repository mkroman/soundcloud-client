/*
 * Copyright (c) 2014, Mikkel Kroman <mk@maero.dk>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef SOUNDCLOUD_TRACK_H
#define SOUNDCLOUD_TRACK_H

#include <QString>
#include <QList>
#include <QObject>
#include <QJsonObject>

#include "libsoundcloud_global.h"
#include "User.h"

namespace Soundcloud {

class LIBSOUNDCLOUDSHARED_EXPORT Track
{
public:
    static Track fromJson(const QJsonObject& object);

public:
    Track();
    ~Track();

    int id() const;
    void setId(int id);

    QString createdAt() const;
    void setCreatedAt(const QString &createdAt);

    User user() const;
    void setUser(const User &user);

    int userId() const;
    void setUserId(int userId);

    QString title() const;
    void setTitle(const QString &title);

    QString permalink() const;
    void setPermalink(const QString &permalink);

    QString permalinkUrl() const;
    void setPermalinkUrl(const QString &permalinkUrl);

    QString apiUri() const;
    void setApiUri(const QString &apiUri);

    // FIXME: This should be an enum
    QString sharing() const;
    void setSharing(const QString &sharing);

    // FIXME: This should be an enum
    QString embeddableBy() const;
    void setEmbeddableBy(const QString &embeddableBy);

    QString purchaseUrl() const;
    void setPurchaseUrl(const QString &purchaseUrl);

    QString artworkUrl() const;
    void setArtworkUrl(const QString &artworkUrl);

    QString description() const;
    void setDescription(const QString &description);

    QString label() const;
    void setLabel(const QString &label);

    int duration() const;
    void setDuration(int duration);

    QString genre() const;
    void setGenre(const QString &genre);

    QString tagList() const;
    void setTagList(const QString &tagList);

    int labelId() const;
    void setLabelId(int labelId);

    QString labelName() const;
    void setLabelName(const QString &labelName);

    int releaseNum() const;
    void setReleaseNum(int releaseNum);

    int releaseDay() const;
    void setReleaseDay(int releaseDay);

    int releaseMonth() const;
    void setReleaseMonth(int releaseMonth);

    int releaseYear() const;
    void setReleaseYear(int releaseYear);

    bool streamable() const;
    void setStreamable(bool streamable);

    bool downloadable() const;
    void setDownloadable(bool downloadable);

    // FIXME: This should be an enum
    QString encodingState() const;
    void setEncodingState(const QString &encodingState);

    // FIXME: Should this be an enum?
    QString license() const;
    void setLicense(const QString &license);

    // FIXME: This should be an enum
    QString trackType() const;
    void setTrackType(const QString &trackType);

    QString waveformUrl() const;
    void setWaveformUrl(const QString &waveformUrl);

    QString downloadUrl() const;
    void setDownloadUrl(const QString &downloadUrl);

    QString streamUrl() const;
    void setStreamUrl(const QString &streamUrl);

    QString videoUrl() const;
    void setVideoUrl(const QString &videoUrl);

    int bpm() const;
    void setBpm(int bpm);

    bool commentable() const;
    void setCommentable(bool commentable);

    QString isrc() const;
    void setIsrc(const QString &isrc);

    QString keySignature() const;
    void setKeySignature(const QString &keySignature);

    int commentCount() const;
    void setCommentCount(int commentCount);

    int downloadCount() const;
    void setDownloadCount(int downloadCount);

    int playbackCount() const;
    void setPlaybackCount(int playbackCount);

    int favoritingsCount() const;
    void setFavoritingsCount(int favoritingsCount);

    QString originalFormat() const;
    void setOriginalFormat(const QString &originalFormat);

    qint64 originalContentSize() const;
    void setOriginalContentSize(const qint64 &originalContentSize);

    bool userFavorite() const;
    void setUserFavorite(bool userFavorite);

private:
    int id_;
    QString createdAt_;
    User user_;
    int userId_;
    QString title_;
    QString permalink_;
    QString permalinkUrl_;
    QString apiUri_;
    QString sharing_;
    QString embeddableBy_;
    QString purchaseUrl_;
    QString artworkUrl_;
    QString description_;
    QString label_;
    int duration_; /// Should cover ~49.71 days of playtime
    QString genre_;
    int shareCount_;
    QString tagList_;
    int labelId_;
    QString labelName_;
    int releaseNum_;
    int releaseDay_;
    int releaseMonth_;
    int releaseYear_;
    bool streamable_;
    bool downloadable_;
    QString encodingState_;
    QString license_;
    QString trackType_;
    QString waveformUrl_;
    QString downloadUrl_;
    QString streamUrl_;
    QString videoUrl_;
    int bpm_;
    bool commentable_;
    QString isrc_;
    QString keySignature_;
    int commentCount_;
    int downloadCount_;
    int playbackCount_;
    int favoritingsCount_;
    QString originalFormat_;
    qint64 originalContentSize_;
    bool userFavorite_;
};

typedef QList<Track> TrackList;

} // namespace Soundcloud

#endif // SOUNDCLOUD_TRACK_H
