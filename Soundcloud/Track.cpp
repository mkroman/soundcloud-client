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

#include "Track.h"

namespace Soundcloud {

Track Track::fromJson(const QJsonObject& object)
{
    Track track;

    track.id_ = object["id"].toInt();
    track.createdAt_ = object["created_at"].toString();
    track.userId_ = object["user_id"].toInt();
    track.title_ = object["title"].toString();
    track.permalink_ = object["permalink"].toString();
    track.permalinkUrl_ = object["permalink_url"].toString();
    track.apiUri_ = object["uri"].toString();
    track.sharing_ = object["sharing"].toString();
    track.embeddableBy_ = object["embeddable_by"].toString();
    track.purchaseUrl_ = object["purchase_url"].toString();
    track.artworkUrl_ = object["artwork_url"].toString();
    track.description_ = object["description"].toString();
    track.duration_ = object["duration"].toInt();
    track.genre_ = object["genre"].toString();
    track.shareCount_ = object["shared_to_count"].toInt();
    track.tagList_ = object["tag_list"].toString();
    track.labelId_ = object["label_id"].toInt();
    track.labelName_ = object["label_name"].toString();
    track.releaseNum_ = object["release"].toInt();
    track.releaseDay_ = object["release_day"].toInt();
    track.releaseMonth_ = object["release_month"].toInt();
    track.releaseYear_ = object["release_year"].toInt();
    track.streamable_ = object["streamable"].toBool();
    track.downloadable_ = object["downloadable"].toBool();
    track.encodingState_ = object["state"].toString();
    track.license_ = object["license"].toString();
    track.trackType_ = object["track_type"].toString();
    track.waveformUrl_ = object["waveform_url"].toString();
    track.downloadUrl_ = object["download_url"].toString();
    track.streamUrl_ = object["stream_url"].toString();
    track.videoUrl_ = object["video_url"].toString();
    track.bpm_ = object["bpm"].toInt();
    track.commentable_ = object["commentable"].toBool();
    track.isrc_ = object["isrc"].toString();
    track.keySignature_ = object["key_signature"].toString();
    track.commentCount_ = object["comment_count"].toInt();
    track.downloadCount_ = object["download_count"].toInt();
    track.playbackCount_ = object["playback_count"].toInt();
    track.favoritingsCount_ = object["favoritings_count"].toInt();
    track.originalFormat_ = object["original_format"].toString();
    track.originalContentSize_ = object["original_content_size"].toDouble();
    track.userFavorite_ = object["user_favorite"].toBool();

    return track;
}

Track::Track()
{
}

int Track::id() const
{
    return id_;
}

void Track::setId(int id)
{
    id_ = id;
}

QString Track::createdAt() const
{
    return createdAt_;
}

void Track::setCreatedAt(const QString &createdAt)
{
    createdAt_ = createdAt;
}

int Track::userId() const
{
    return userId_;
}

void Track::setUserId(int userId)
{
    userId_ = userId;
}

QString Track::title() const
{
    return title_;
}

void Track::setTitle(const QString &title)
{
    title_ = title;
}

QString Track::permalink() const
{
    return permalink_;
}

void Track::setPermalink(const QString &permalink)
{
    permalink_ = permalink;
}

QString Track::permalinkUrl() const
{
    return permalinkUrl_;
}

void Track::setPermalinkUrl(const QString &permalinkUrl)
{
    permalinkUrl_ = permalinkUrl;
}

QString Track::apiUri() const
{
    return apiUri_;
}

void Track::setApiUri(const QString &apiUri)
{
    apiUri_ = apiUri;
}

QString Track::sharing() const
{
    return sharing_;
}

void Track::setSharing(const QString &sharing)
{
    sharing_ = sharing;
}

QString Track::embeddableBy() const
{
    return embeddableBy_;
}

void Track::setEmbeddableBy(const QString &embeddableBy)
{
    embeddableBy_ = embeddableBy;
}

QString Track::purchaseUrl() const
{
    return purchaseUrl_;
}

void Track::setPurchaseUrl(const QString &purchaseUrl)
{
    purchaseUrl_ = purchaseUrl;
}

QString Track::artworkUrl() const
{
    return artworkUrl_;
}

void Track::setArtworkUrl(const QString &artworkUrl)
{
    artworkUrl_ = artworkUrl;
}

QString Track::description() const
{
    return description_;
}

void Track::setDescription(const QString &description)
{
    description_ = description;
}

QString Track::label() const
{
    return label_;
}

void Track::setLabel(const QString &label)
{
    label_ = label;
}

int Track::duration() const
{
    return duration_;
}

void Track::setDuration(int duration)
{
    duration_ = duration;
}

QString Track::genre() const
{
    return genre_;
}

void Track::setGenre(const QString &genre)
{
    genre_ = genre;
}

QString Track::tagList() const
{
    return tagList_;
}

void Track::setTagList(const QString &tagList)
{
    tagList_ = tagList;
}

int Track::labelId() const
{
    return labelId_;
}

void Track::setLabelId(int labelId)
{
    labelId_ = labelId;
}

QString Track::labelName() const
{
    return labelName_;
}

void Track::setLabelName(const QString &labelName)
{
    labelName_ = labelName;
}

int Track::releaseNum() const
{
    return releaseNum_;
}

void Track::setReleaseNum(int releaseNum)
{
    releaseNum_ = releaseNum;
}

int Track::releaseDay() const
{
    return releaseDay_;
}

void Track::setReleaseDay(int releaseDay)
{
    releaseDay_ = releaseDay;
}

int Track::releaseMonth() const
{
    return releaseMonth_;
}

void Track::setReleaseMonth(int releaseMonth)
{
    releaseMonth_ = releaseMonth;
}

int Track::releaseYear() const
{
    return releaseYear_;
}

void Track::setReleaseYear(int releaseYear)
{
    releaseYear_ = releaseYear;
}

bool Track::streamable() const
{
    return streamable_;
}

void Track::setStreamable(bool streamable)
{
    streamable_ = streamable;
}

bool Track::downloadable() const
{
    return downloadable_;
}

void Track::setDownloadable(bool downloadable)
{
    downloadable_ = downloadable;
}

QString Track::encodingState() const
{
    return encodingState_;
}

void Track::setEncodingState(const QString &encodingState)
{
    encodingState_ = encodingState;
}

QString Track::license() const
{
    return license_;
}

void Track::setLicense(const QString &license)
{
    license_ = license;
}

QString Track::trackType() const
{
    return trackType_;
}

void Track::setTrackType(const QString &trackType)
{
    trackType_ = trackType;
}

QString Track::waveformUrl() const
{
    return waveformUrl_;
}

void Track::setWaveformUrl(const QString &waveformUrl)
{
    waveformUrl_ = waveformUrl;
}

QString Track::downloadUrl() const
{
    return downloadUrl_;
}

void Track::setDownloadUrl(const QString &downloadUrl)
{
    downloadUrl_ = downloadUrl;
}

QString Track::streamUrl() const
{
    return streamUrl_;
}

void Track::setStreamUrl(const QString &streamUrl)
{
    streamUrl_ = streamUrl;
}

QString Track::videoUrl() const
{
    return videoUrl_;
}

void Track::setVideoUrl(const QString &videoUrl)
{
    videoUrl_ = videoUrl;
}

int Track::bpm() const
{
    return bpm_;
}

void Track::setBpm(int bpm)
{
    bpm_ = bpm;
}

bool Track::commentable() const
{
    return commentable_;
}

void Track::setCommentable(bool commentable)
{
    commentable_ = commentable;
}

QString Track::isrc() const
{
    return isrc_;
}

void Track::setIsrc(const QString &isrc)
{
    isrc_ = isrc;
}

QString Track::keySignature() const
{
    return keySignature_;
}

void Track::setKeySignature(const QString &keySignature)
{
    keySignature_ = keySignature;
}

int Track::commentCount() const
{
    return commentCount_;
}

void Track::setCommentCount(int commentCount)
{
    commentCount_ = commentCount;
}

int Track::downloadCount() const
{
    return downloadCount_;
}

void Track::setDownloadCount(int downloadCount)
{
    downloadCount_ = downloadCount;
}

int Track::playbackCount() const
{
    return playbackCount_;
}

void Track::setPlaybackCount(int playbackCount)
{
    playbackCount_ = playbackCount;
}

int Track::favoritingsCount() const
{
    return favoritingsCount_;
}

void Track::setFavoritingsCount(int favoritingsCount)
{
    favoritingsCount_ = favoritingsCount;
}

QString Track::originalFormat() const
{
    return originalFormat_;
}

void Track::setOriginalFormat(const QString &originalFormat)
{
    originalFormat_ = originalFormat;
}

qint64 Track::originalContentSize() const
{
    return originalContentSize_;
}

void Track::setOriginalContentSize(const qint64 &originalContentSize)
{
    originalContentSize_ = originalContentSize;
}

bool Track::userFavorite() const
{
    return userFavorite_;
}

void Track::setUserFavorite(bool userFavorite)
{
    userFavorite_ = userFavorite;
}











































} // namespace Soundcloud
