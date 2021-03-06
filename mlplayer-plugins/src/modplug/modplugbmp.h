/* Modplug XMMS Plugin
 * Authors: Kenton Varda <temporal@gauge3d.org>
 *
 * This source code is public domain.
 */

#ifndef __MODPLUGXMMS_CMODPLUGXMMS_H_INCLUDED__
#define __MODPLUGXMMS_CMODPLUGXMMS_H_INCLUDED__

#include <string>
#include <glib.h>
#include "stddefs.h"

extern "C" {
#include <mlplayer/plugin.h>
}

/* Module files have their magic deep inside the file, at offset 1080; source: http://www.onicos.com/staff/iz/formats/mod.html and information by Michael Doering from UADE */
#define MOD_MAGIC_PROTRACKER4	"M.K."  // Protracker 4 channel
#define MOD_MAGIC_PROTRACKER4X	"M!K!"  // Protracker 4 channel
#define MOD_MAGIC_NOISETRACKER	"M&K!"  // Noisetracker 1.3 by Kaktus & Mahoney
#define MOD_MAGIC_STARTRACKER4	"FLT4"  // Startracker 4 channel (Startrekker/AudioSculpture)
#define MOD_MAGIC_STARTRACKER8	"FLT8"  // Startracker 8 channel (Startrekker/AudioSculpture)
#define MOD_MAGIC_STARTRACKER4X	"EX04"  // Startracker 4 channel (Startrekker/AudioSculpture)
#define MOD_MAGIC_STARTRACKER8X	"EX08"  // Startracker 8 channel (Startrekker/AudioSculpture)
#define MOD_MAGIC_FASTTRACKER4	"4CHN"  // Fasttracker 4 channel
#define MOD_MAGIC_OKTALYZER8	"CD81"  // Atari oktalyzer 8 channel
#define MOD_MAGIC_OKTALYZER8X	"OKTA"  // Atari oktalyzer 8 channel
#define MOD_MAGIC_TAKETRACKER16	"16CN"  // Taketracker 16 channel
#define MOD_MAGIC_TAKETRACKER32 "32CN"  // Taketracker 32 channel

#define S3M_MAGIC	"SCRM"  /* This is the SCRM string at offset 44 to 47 in the S3M header */

/* These nicer formats have the magic bytes at the front of the file where they belong */
#define UMX_MAGIC	"\xC1\x83\x2A\x9E"
#define XM_MAGIC	"Exte"              /* Exte(nded Module) */
#define M669_MAGIC	"if  "              /* Last two bytes are bogus, and not checked */
#define IT_MAGIC	"IMPM"              /* IMPM */
#define MTM_MAGIC	"\x4D\x54\x4D\x10"
#define PSM_MAGIC	"PSM "

using namespace std;

class CSoundFile;
class Archive;

class ModplugXMMS
{
public:
	struct Settings
	{
		gboolean   mSurround;
		gboolean   mOversamp;
		gboolean   mMegabass;
		gboolean   mNoiseReduction;
		gboolean   mVolumeRamp;
		gboolean   mReverb;
		gboolean   mFastinfo;
		gboolean   mUseFilename;
		gboolean   mGrabAmigaMOD;
		gboolean   mPreamp;

		gint       mChannels;
		gint       mBits;
		gint       mFrequency;
		gint       mResamplingMode;

		gint       mReverbDepth;
		gint       mReverbDelay;
		gint       mBassAmount;
		gint       mBassRange;
		gint       mSurroundDepth;
		gint       mSurroundDelay;
		gfloat     mPreampLevel;
		gint       mLoopCount;
	};

	ModplugXMMS();
	~ModplugXMMS();

	void Init();                      // Called when the plugin is loaded
	bool CanPlayFileFromVFS(const string& aFilename, VFSFile *file);	// Return true if the plugin can handle the file

	void CloseConfigureBox();

	bool PlayFile(const string& aFilename, InputPlayback *data);// Play the file.
	void Stop(InputPlayback *data);         // Stop playing.
	void mseek (InputPlayback * playback, gint time);
	void pause (InputPlayback * playback, gboolean paused);

	Tuple* GetSongTuple(const string& aFilename);

	void SetInputPlugin(InputPlugin& aInPlugin);

	const Settings& GetModProps();
	void SetModProps(const Settings& aModProps);

private:
	InputPlugin*  mInPlug;

	uchar*  mBuffer;
	uint32  mBufSize;

    GMutex * control_mutex;
    GCond * control_cond;
    gint seek_time;
	bool          mPaused;

	Settings mModProps;

	gint mFormat;

	uint32  mBufTime;		//milliseconds

	CSoundFile* mSoundFile;
	Archive*    mArchive;

	char        mModName[100];

	float mPreampFactor;

	void PlayLoop(InputPlayback *);
	const char* Bool2OnOff(bool aValue);
};

extern ModplugXMMS gModplugXMMS;

#endif //included
