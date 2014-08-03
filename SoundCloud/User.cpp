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

#include <QDebug>
#include "User.h"

namespace SoundCloud {



User User::fromJson(const QJsonObject& object)
{
    User user;

    user.id_ = object["id"].toInt();
    user.permalink_ = object["permalink"].toString();
    user.name_ = object["username"].toString();
    user.apiUri_ = object["uri"].toString();
    user.permalinkUrl_ = object["permalink_url"].toString();
    user.avatarUrl_ = object["avatar_url"].toString();
    user.country_ = object["country"].toString();
    user.fullName_ = object["full_name"].toString();
    user.city_ = object["city"].toString();
    user.description_ = object["description"].toString();
    user.discogsName_ = object["discogs-name"].toString();
    user.myspaceName_ = object["myspace-name"].toString();
    user.website_ = object["website"].toString();
    user.websiteTitle_ = object["website-title"].toString();
    user.online_ = object["online"].toBool();
    user.trackCount_ = object["track_count"].toInt();
    user.playlistCount_ = object["playlist_count"].toInt();
    user.followersCount_ = object["followers_count"].toInt();
    user.followingsCount_ = object["followings_count"].toInt();
    user.publicFavoritesCount_ = object["public_favorites_count"].toInt();

    // These are only present if the user is the actual user that is signed in
    user.plan_ = object["plan"].toString();
    user.privateTracksCount_ = object["private_tracks_count"].toInt();
    user.privatePlaylistsCount_ = object["private_playlists_count"].toInt();
    user.primaryEmailConfirmed_ = object["primary_email_confirmed"].toBool();

    return user;
}

User::User()
{
}

User::~User()
{
}

int User::id() const
{
    return id_;
}

void User::setId(int id)
{
    id_ = id;
}

QString User::name() const
{
    return name_;
}

void User::setName(const QString &name)
{
    name_ = name;
}

QString User::permalink() const
{
    return permalink_;
}

void User::setPermalink(const QString &permalink)
{
    permalink_ = permalink;
}

QString User::apiUri() const
{
    return apiUri_;
}

void User::setApiUri(const QString &apiUri)
{
    apiUri_ = apiUri;
}

QString User::permalinkUrl() const
{
    return permalinkUrl_;
}

void User::setPermalinkUrl(const QString &permalinkUrl)
{
    permalinkUrl_ = permalinkUrl;
}

QString User::avatarUrl() const
{
    return avatarUrl_;
}

void User::setAvatarUrl(const QString &avatarUrl)
{
    avatarUrl_ = avatarUrl;
}

QString User::country() const
{
    return country_;
}

void User::setCountry(const QString &country)
{
    country_ = country;
}

QString User::fullName() const
{
    return fullName_;
}

void User::setFullName(const QString &fullName)
{
    fullName_ = fullName;
}

QString User::city() const
{
    return city_;
}

void User::setCity(const QString &city)
{
    city_ = city;
}

QString User::description() const
{
    return description_;
}

void User::setDescription(const QString &description)
{
    description_ = description;
}

QString User::discogsName() const
{
    return discogsName_;
}

void User::setDiscogsName(const QString &discogsName)
{
    discogsName_ = discogsName;
}

QString User::myspaceName() const
{
    return myspaceName_;
}

void User::setMyspaceName(const QString &myspaceName)
{
    myspaceName_ = myspaceName;
}

QString User::website() const
{
    return website_;
}

void User::setWebsite(const QString &website)
{
    website_ = website;
}

QString User::websiteTitle() const
{
    return websiteTitle_;
}

void User::setWebsiteTitle(const QString &websiteTitle)
{
    websiteTitle_ = websiteTitle;
}

bool User::isOnline() const
{
    return online_;
}

void User::setOnline(bool online)
{
    online_ = online;
}

int User::trackCount() const
{
    return trackCount_;
}

void User::setTrackCount(int trackCount)
{
    trackCount_ = trackCount;
}

int User::playlistCount() const
{
    return playlistCount_;
}

void User::setPlaylistCount(int playlistCount)
{
    playlistCount_ = playlistCount;
}

int User::followersCount() const
{
    return followersCount_;
}

void User::setFollowersCount(int followersCount)
{
    followersCount_ = followersCount;
}

int User::followingsCount() const
{
    return followingsCount_;
}

void User::setFollowingsCount(int followingsCount)
{
    followingsCount_ = followingsCount;
}

int User::publicFavoritesCount() const
{
    return publicFavoritesCount_;
}

void User::setPublicFavoritesCount(int publicFavoritesCount)
{
    publicFavoritesCount_ = publicFavoritesCount;
}

QString User::plan() const
{
    return plan_;
}

void User::setPlan(const QString &plan)
{
    plan_ = plan;
}

int User::privateTracksCount() const
{
    return privateTracksCount_;
}

void User::setPrivateTracksCount(int privateTracksCount)
{
    privateTracksCount_ = privateTracksCount;
}

int User::privatePlaylistsCount() const
{
    return privatePlaylistsCount_;
}

void User::setPrivatePlaylistsCount(int privatePlaylistsCount)
{
    privatePlaylistsCount_ = privatePlaylistsCount;
}

bool User::primaryEmailConfirmed() const
{
    return primaryEmailConfirmed_;
}

void User::setPrimaryEmailConfirmed(bool primaryEmailConfirmed)
{
    primaryEmailConfirmed_ = primaryEmailConfirmed;
}


} // namespace Soundcloud
