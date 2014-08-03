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

#ifndef SOUNDCLOUD_USER_H
#define SOUNDCLOUD_USER_H

#include <QUrl>
#include <QString>
#include <QJsonObject>

#include "libsoundcloud_global.h"

namespace SoundCloud {

class LIBSOUNDCLOUDSHARED_EXPORT User
{
public:
    static User fromJson(const QJsonObject& object);

public:
    User();
    ~User();


    int id() const;
    void setId(int id);

    /// The username.
    ///
    /// \return The username.
    QString name() const;

    /// Set the username.
    void setName(const QString &name);

    QString permalink() const;
    void setPermalink(const QString &permalink);

    QString apiUri() const;
    void setApiUri(const QString &apiUri);

    QString permalinkUrl() const;
    void setPermalinkUrl(const QString &permalinkUrl);

    QString avatarUrl() const;
    void setAvatarUrl(const QString &avatarUrl);

    QString country() const;
    void setCountry(const QString &country);

    QString fullName() const;
    void setFullName(const QString &fullName);

    QString city() const;
    void setCity(const QString &city);

    QString description() const;
    void setDescription(const QString &description);

    /// The discogs name.
    ///
    /// \return The discogs name.
    QString discogsName() const;
    void setDiscogsName(const QString &discogsName);

    QString myspaceName() const;
    void setMyspaceName(const QString &myspaceName);

    QString website() const;
    void setWebsite(const QString &website);

    QString websiteTitle() const;
    void setWebsiteTitle(const QString &websiteTitle);

    bool isOnline() const;
    void setOnline(bool online);

    int trackCount() const;
    void setTrackCount(int trackCount);

    int playlistCount() const;
    void setPlaylistCount(int playlistCount);

    int followersCount() const;
    void setFollowersCount(int followersCount);

    int followingsCount() const;
    void setFollowingsCount(int followingsCount);

    int publicFavoritesCount() const;
    void setPublicFavoritesCount(int publicFavoritesCount);

    QString plan() const;
    void setPlan(const QString &plan);

    int privateTracksCount() const;
    void setPrivateTracksCount(int privateTracksCount);

    int privatePlaylistsCount() const;
    void setPrivatePlaylistsCount(int privatePlaylistsCount);

    bool primaryEmailConfirmed() const;
    void setPrimaryEmailConfirmed(bool primaryEmailConfirmed);

private:
    int id_;

    /// The username
    QString name_;

    /// Permalink of the resource
    QString permalink_;

    /// API resource URL
    QString apiUri_;

    /// URL to the SoundCloud.com page
    QString permalinkUrl_;

    /// URL to a JPEG image
    QString avatarUrl_;

    /// Country
    QString country_;

    /// First and last name
    QString fullName_;

    /// City
    QString city_;

    /// Description
    QString description_;

    /// Discogs name
    QString discogsName_;

    /// MySpace name
    QString myspaceName_;

    /// A URL to the website
    QString website_;

    /// A custom title for the website
    QString websiteTitle_;

    /// Is the user online
    bool online_;

    /// Number of tracks uploaded
    int trackCount_;

    /// Number of playlists
    int playlistCount_;

    /// Number of followers
    int followersCount_;

    /// Number of followings
    int followingsCount_;

    /// Number of favorites
    int publicFavoritesCount_;

    /// Subscription plan
    QString plan_;

    /// Number of private tracks
    int privateTracksCount_;

    /// Number of private playlists
    int privatePlaylistsCount_;

    /// Is the primary e-mail confirmed
    bool primaryEmailConfirmed_;
};

} // namespace Soundcloud

#endif // SOUNDCLOUD_USER_H
