/**
 * @file config.c  Core Configuration
 *
 * Copyright (C) 2010 Creytiv.com
 */
#include <re.h>
#include <rem.h>
#include <baresip.h>
#include "core.h"


#define DEBUG_MODULE "config"
#define DEBUG_LEVEL 5
#include <re_dbg.h>


#undef MOD_PRE
#define MOD_PRE ""  /**< Module prefix */


/** Core Run-time Configuration - populated from config file */
/* todo: move parsing/decoding to a module */
static struct config core_config = {
	/** SIP User-Agent */
	{
		16,
		"",
		"",
		""
	},

	/** Audio */
	{
		"","",
		"","",
		"","",
		"","",
		{8000, 48000},
		{1, 2},
		0,
		0,
		false,
		AUDIO_MODE_POLL,
		128, 128			// softvol tx, rx, \sa SOFTVOL_BASE
	},

#ifdef USE_VIDEO
	/** Video */
	{
		"", "",
		352, 288,
		512000,
		25,
	},
#endif

	/** Audio/Video Transport */
	{
		0xb8,
		{1024, 49152},
		{512000, 1024000},
		true,
		false,
		{5, 10},
		0
	},

	SOUND_PORTAUDIO_DSOUND,

	/* recording */
	{
		false
	},

	/* tx preprocessor */
	{
		false,
		true,
		false,
		false,
		false,
		8000
	},

	AEC_WEBRTC,

	/* WebRTC AEC */
	{
		120,
		0
	},

	/* Network */
	{
		""
	},

#ifdef USE_VIDEO
	/* BFCP */
	{
		""
	},
#endif
};

static int dns_server_handler(const struct pl *pl, void *arg)
{
	struct sa sa;
	int err;

	(void)arg;

	err = sa_decode(&sa, pl->p, pl->l);
	if (err) {
		DEBUG_WARNING("dns_server: could not decode `%r'\n", pl);
		return err;
	}

	err = net_dnssrv_add(&sa);
	if (err) {
		DEBUG_WARNING("failed to add nameserver %r: %m\n", pl, err);
	}

	return err;
}

struct config *conf_config(void)
{
	return &core_config;
}
