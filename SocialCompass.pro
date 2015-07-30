!include("../Common/retroshare_plugin.pri"): error("Could not include file ../Common/retroshare_plugin.pri")

CONFIG += qt uic qrc resources

greaterThan(QT_MAJOR_VERSION, 4) {
	# Qt 5
	QT     += widgets
} 

SOURCES = SocialCompassPlugin.cpp \
    topjcdialog.cpp
HEADERS = SocialCompassPlugin.h \
    topjcdialog.h
FORMS   = \
    topjcdialog.ui

TARGET = SocialCompass

RESOURCES = SocialCompass_images.qrc

TRANSLATIONS +=  \
                        lang/SocialCompass_cs.ts \
                        lang/SocialCompass_da.ts \
                        lang/SocialCompass_de.ts \
                        lang/SocialCompass_el.ts \
                        lang/SocialCompass_en.ts \
                        lang/SocialCompass_es.ts \
                        lang/SocialCompass_fi.ts \
                        lang/SocialCompass_fr.ts \
                        lang/SocialCompass_hu.ts \
                        lang/SocialCompass_it.ts \
                        lang/SocialCompass_ja_JP.ts \
                        lang/SocialCompass_ko.ts \
                        lang/SocialCompass_nl.ts \
                        lang/SocialCompass_pl.ts \
                        lang/SocialCompass_ru.ts \
                        lang/SocialCompass_sv.ts \
                        lang/SocialCompass_tr.ts \
                        lang/SocialCompass_zh_CN.ts

OTHER_FILES += \
    testit.sh
