#include <QDir>
#include <QSound>
#include <QCoreApplication>
#include <QDebug>

#include "audioPlayer.h"
#include "types.h"


AudioPlayer::AudioPlayer()
{
	qDebug() << QCoreApplication::applicationDirPath();

	settings.setValue((SettingsKey::VOLUME_KEY), 100);
	if (settings.contains(SettingsKey::VOLUME_KEY)){
		int vol = settings.value(SettingsKey::VOLUME_KEY).toInt();
		sound.setVolume(vol);
	}
	else{
		sound.setVolume(50);
		settings.setValue((SettingsKey::VOLUME_KEY), 50);
	}
	if (settings.contains(SettingsKey::MUTE_KEY)){
		mIsMute = settings.value(SettingsKey::MUTE_KEY).toBool();
	}
	else{
		settings.setValue((SettingsKey::MUTE_KEY), 0);
		mIsMute = false;
	}
	path = QDir::currentPath();
}

void AudioPlayer::mute(bool isMute)
{
	mIsMute = isMute;
	settings.setValue((SettingsKey::MUTE_KEY), isMute);
}


void AudioPlayer::setVolume(int value)
{
	settings.setValue((SettingsKey::VOLUME_KEY), value);
	sound.setVolume(value);
}

void AudioPlayer::playSound(Sounds track)
{
	if (mIsMute)
		return;
	switch (track)
	{
		case (BEGIN_SOUND):
			sound.setMedia(QUrl::fromLocalFile(soundFolder() + "begin.mp3"));
		break;
		case(FIRST_BLOOD):
			sound.setMedia(QUrl::fromLocalFile(soundFolder() + "first blood.mp3"));
		break;
		case(MISS_SOUND):
			sound.setMedia(QUrl::fromLocalFile(soundFolder() + "miss.mp3"));
		break;
		case(WOUNDED_SOUND):
			sound.setMedia(QUrl::fromLocalFile(soundFolder() + "wounded.mp3"));
		break;
		case(KILLED_SOUND):
			sound.setMedia(QUrl::fromLocalFile(soundFolder() + "killed.mp3"));
		break;
		case(FINISH_HIM):
			sound.setMedia(QUrl::fromLocalFile(soundFolder() + "finish him.mp3"));
		break;
		case(VICTORY_SOUND):
			sound.setMedia(QUrl::fromLocalFile(soundFolder() + "victory.mp3"));
		break;
		case(DEFEAT_SOUND):
			sound.setMedia(QUrl::fromLocalFile(soundFolder() + "defeat.mp3"));
		break;
		case(SHIP_SET_SOUND):
			sound.setMedia(QUrl::fromLocalFile(soundFolder() + "ship_set.mp3"));
		break;
		case(SHIP_SET_ERR_SOUND):
			sound.setMedia(QUrl::fromLocalFile(soundFolder() + "ship_set_error.mp3"));
	}
	sound.play();

}

void AudioPlayer::playBackground()
{
	if(mIsMute)
		return;
	background.setMedia(QUrl::fromLocalFile(soundFolder() + "sea.mp3"));
	background.play();
}

void AudioPlayer::stopBackground()
{
	background.stop();
}

QString AudioPlayer::soundFolder()
{
	static QString folder = QCoreApplication::applicationDirPath() + "/sounds/";
	return folder;
}
