target_include_directories(apps-common

	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}"
)

target_sources(apps-common
	PRIVATE
		HomeModesWindow.cpp
		Popups.cpp
		PowerOffWindow.cpp
		AlarmPopup.cpp
		TetheringConfirmationPopup.cpp
		TetheringNotificationPopup.cpp
		TetheringPhoneModePopup.cpp
		TetheringOffPopup.cpp
		TetheringMenuPopup.cpp
		BluetoothAuthenticatePopup.cpp
		BluetoothInfoPopup.cpp
		VolumeWindow.cpp
		WindowWithTimer.cpp
		lock-popups/PhoneLockedInfoWindow.cpp
		lock-popups/PhoneLockedWindow.cpp
		lock-popups/PhoneLockInputWindow.cpp
		lock-popups/PhoneLockChangeInfoWindow.cpp
		lock-popups/SimLockInputWindow.cpp
		lock-popups/SimInfoWindow.cpp
		lock-popups/SimNotReadyWindow.cpp
		lock-popups/SimSwitchingWindow.cpp
		lock-popups/phone-lock-wallpapers/WallpaperBase.cpp
		lock-popups/phone-lock-wallpapers/WallpaperClock.cpp
		lock-popups/phone-lock-wallpapers/WallpaperQuote.cpp
		lock-popups/phone-lock-wallpapers/WallpaperLogo.cpp
		presenter/PowerOffPresenter.cpp
		presenter/AlarmPresenter.cpp
		data/PopupRequestParamsBase.cpp
		presenter/QuotesPresenter.cpp
		presenter/WallpaperPresenter.cpp
	PRIVATE
		HomeModesWindow.hpp
		Popups.hpp
		PowerOffWindow.hpp
		AlarmPopup.hpp
		TetheringConfirmationPopup.hpp
		TetheringNotificationPopup.hpp
		TetheringPhoneModePopup.hpp
		TetheringMenuPopup.hpp
		BluetoothAuthenticatePopup.hpp
		BluetoothInfoPopup.hpp
		VolumeWindow.hpp
		WindowWithTimer.hpp
		data/PopupData.hpp
		lock-popups/PhoneLockedInfoData.hpp
		lock-popups/PhoneLockedInfoWindow.hpp
		lock-popups/PhoneLockedWindow.hpp
		lock-popups/PhoneLockInputWindow.hpp
		lock-popups/PhoneLockChangeInfoWindow.hpp
		lock-popups/SimLockInputWindow.hpp
		lock-popups/SimInfoWindow.hpp
		lock-popups/SimNotReadyWindow.hpp
		lock-popups/SimSwitchingWindow.hpp
		lock-popups/phone-lock-wallpapers/WallpaperBase.hpp
		lock-popups/phone-lock-wallpapers/WallpaperClock.hpp
		lock-popups/phone-lock-wallpapers/WallpaperQuote.hpp
		lock-popups/phone-lock-wallpapers/WallpaperLogo.hpp
		presenter/PowerOffPresenter.hpp
		presenter/QuotesPresenter.hpp
		presenter/WallpaperPresenter.hpp
)
