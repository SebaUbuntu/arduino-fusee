#pragma once

enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_FATAL,
    LOG_LEVEL_MAX,
};

#ifndef LOG_LEVEL
#ifdef DEBUG
#define LOG_LEVEL LOG_LEVEL_DEBUG
#else
#define LOG_LEVEL LOG_LEVEL_INFO
#endif
#endif

extern const String LOG_LEVEL_STRING[];

#define _LOG(level, fmt) { \
    if (level > LOG_LEVEL) \
        Serial.println(LOG_LEVEL_STRING[level] + ": " fmt); \
}

#define LOGD(str) _LOG(LOG_LEVEL_DEBUG, str)
#define LOGI(str) _LOG(LOG_LEVEL_INFO, str)
#define LOGW(str) _LOG(LOG_LEVEL_WARN, str)
#define LOGE(str) _LOG(LOG_LEVEL_ERROR, str)
#define LOGF(str) _LOG(LOG_LEVEL_FATAL, str)
