# Copyright (c) 2013-2018 LG Electronics, Inc.

# A blacklisted recipe is ignored by bitbake. The reason it is useful to be able
# to have bitbake ignore a recipe is because, although PREFERRED_PROVIDER can be
# used to select which recipe is used to fulfill a build-time dependency, bitbake
# does not have a PREFERRED_RPROVIDER to allow specification of which package
# should be used to satisfy a run-time dependency. When two recipes both provide
# common packages, but one recipe provides additional packages that the other
# doesn't, then the only way to guarantee that the first recipe will never be
# used is to blacklist it.

# Be aware that changes in this file usually doesn't trigger reparsing
# to force it manually you can remove BUILD-*/cache directory, this will
# be solved by backporting this patch into bitbake version we're using:
# http://lists.openembedded.org/pipermail/bitbake-devel/2013-July/003624.html

# Unused in webOS world, blacklisted to allow to build world faster

# Remove virtual/libx11 dependency and add wayland, because one of them need to be selected
# Must enable at least one of: waffle_has_glx, waffle_has_wayland, waffle_has_x11_egl, waffle_has_gbm.
PACKAGECONFIG_pn-waffle= "wayland"

# Remove dracut dependency, because we don't include meta-initramfs
PACKAGECONFIG_remove_pn-plymouth = "initrd"

PNBLACKLIST[qt4-embedded] ?= "unused in webOS world"
PNBLACKLIST[webkit-gtk] ?= "unused in webOS world"
PNBLACKLIST[asio] ?= "unused in webOS world"
PNBLACKLIST[abiword] ?= "unused in webOS world"
PNBLACKLIST[mongodb] ?= "unused in webOS world"

PNBLACKLIST[llvm2.8] ?= "we prefer 3.2+"
PNBLACKLIST[llvm2.9] ?= "we prefer 3.2+"
PNBLACKLIST[llvm2.8-native] ?= "we prefer 3.2+"
PNBLACKLIST[llvm2.9-native] ?= "we prefer 3.2+"

PNBLACKLIST[packagegroup-core-qt] ?= "rdepends on blacklisted quicky, fotowall"
PNBLACKLIST[packagegroup-qt-toolchain-target] ?= "rdepends on blacklisted qt4-mkspecs, libqtmultimedia4-dev, libqtphonon4-dev, libqt3support4-dev, libqtclucene4-dev, libqtcore4-dev, libqtdbus4-dev, libqtdesignercomponents4-dev, libqtdesigner4-dev, libqtuitools4-dev, libqtgui4-dev, libqthelp4-dev, libqtnetwork4-dev, libqtscript4-dev, libqtscripttools4-dev, libqtsql4-dev, libqtsvg4-dev, libqttest4-dev, libqtwebkit4-dev, libqtxml4-dev, libqtdeclarative4-dev, libqtxmlpatterns4-dev, qt4-x11-free-dev, libqtopengl4-dev"
PNBLACKLIST[packagegroup-qte-toolchain-target] ?= "rdepends on blacklisted qt4-embedded-mkspecs, libqt-embeddedmultimedia4-dev, libqt-embeddedphonon4-dev, libqt-embedded3support4-dev, libqt-embeddedclucene4-dev, libqt-embeddedcore4-dev, libqt-embeddeddbus4-dev, libqt-embeddeddesignercomponents4-dev, libqt-embeddeddesigner4-dev, libqt-embeddeduitools4-dev, libqt-embeddedgui4-dev, libqt-embeddedhelp4-dev, libqt-embeddednetwork4-dev, libqt-embeddedscript4-dev, libqt-embeddedscripttools4-dev, libqt-embeddedsql4-dev, libqt-embeddedsvg4-dev, libqt-embeddedtest4-dev, libqt-embeddedwebkit4-dev, libqt-embeddedxml4-dev, libqt-embeddeddeclarative4-dev, libqt-embeddedxmlpatterns4-dev"
PNBLACKLIST[packagegroup-core-qt4e] ?= "rdepends on blacklisted qt4-embedded, libqt-embedded3support4, libqt-embeddedclucene4, libqt-embeddedcore4, libqt-embeddeddbus4, libqt-embeddedgui4, libqt-embeddedhelp4, libqt-embeddedmultimedia4, libqt-embeddednetwork4, libqt-embeddedscript4, libqt-embeddedscripttools4, libqt-embeddedsql4, libqt-embeddedsvg4, libqt-embeddedtest4, libqt-embeddedwebkit4, libqt-embeddedxml4, qt4-embedded-fonts-ttf-dejavu, qt4-embedded-fonts-ttf-vera, qt4-embedded-plugin-iconengine-svgicon, qt4-embedded-plugin-imageformat-gif, qt4-embedded-plugin-imageformat-ico, qt4-embedded-plugin-imageformat-jpeg, qt4-embedded-plugin-imageformat-mng, qt4-embedded-plugin-imageformat-svg, qt4-embedded-plugin-imageformat-tiff, qt4-embedded-plugin-mousedriver-tslib, qt4-embedded-plugin-phonon-backend-gstreamer, qt4-embedded-plugin-script-dbus, qt4-embedded-plugin-sqldriver-sqlite, qt4-embedded-demos, qt4-embedded-examples, qt4-embedded-assistant, packagegroup-core-qt4e"

PNBLACKLIST[libmpc] ?= "depends on newer GMP >= 4.3.2 and we prefer 4.2.1 because of license"
PNBLACKLIST[gcc] ?= "depends on blacklisted libmpc"
PNBLACKLIST[gccmakedep] ?= "depends on blacklisted gcc"
PNBLACKLIST[lcov] ?= "depends on blacklisted gcc (to provide gcov)"
PNBLACKLIST[packagegroup-core-buildessential] ?= "rdepends on blacklisted gcc (to provide cpp, cpp-symlinks, gcc, gcc-symlinks, g++, g++-symlinks)"
PNBLACKLIST[packagegroup-sdk-target] ?= "depends on blacklisted gcc (to provide cpp, cpp-symlinks, gcc, gcc-symlinks, g++, g++-symlinks, g77-symlinks, gfortran-symlinks)"
PNBLACKLIST[packagegroup-core-sdk] ?= "depends on blacklisted gcc"

# Depends on recipe with incompatible LICENSE
PNBLACKLIST[libsdl-mixer] ?= "depends on blacklisted libmad"
PNBLACKLIST[libsdl2-ttf] ?= "fails to build http://caprica.lgsvl.com:8080/Errors/Details/887452"

# Depends on failing recipe:
PNBLACKLIST[uhd] ?= "depends on blacklisted uhd-firmware"

# Depends on unused recipe:
PNBLACKLIST[qt-mobility-embedded] ?= "depends on blacklisted qt4-embedded"
PNBLACKLIST[qconnman-e] ?= "depends on blacklisted qt4-embedded"
PNBLACKLIST[qtserialport-e] ?= "depends on blacklisted qt4-embedded"
PNBLACKLIST[libconnman-qte] ?= "depends on blacklisted qt4-embedded"
PNBLACKLIST[web-webkit] ?= "depends on blacklisted webkit-gtk"
PNBLACKLIST[gimp] ?= "depends on blacklisted webkit-gtk"

# Use webOS qt5 configuration
PNBLACKLIST[qtwebengine] ?= "replaced by new qweless chromium and wam"
PNBLACKLIST[qtwebkit] ?= "depends on blacklisted qtlocation"
PNBLACKLIST[qtwebkit-examples] ?= "depends on qtwebkit"
PNBLACKLIST[qtquick1] ?= "depends on blacklisted qtwebkit"
PNBLACKLIST[qttools] ?= "depends on qtwebkit"
PNBLACKLIST[qt5-creator] ?= "depends on blacklisted qttools"
PNBLACKLIST[qt3d] ?= "license of current version does not allow redistribution"
PNBLACKLIST[qtlocation] ?= "has build dependency on qt3d"
PNBLACKLIST[packagegroup-qt5-toolchain-target] ?= "rdepends on headers from blacklisted qtwebkit, qttools, qt3d, qtlocation"
PNBLACKLIST[qt5-creator] ?= "rdepends on blacklisted qttools, packagegroup-qt5-toolchain-target, gcc-symlinks"
PNBLACKLIST[qtscript] ?= "unused in webOS world"
# https://anaconda.lgsvl.com/jenkins/job/webos-wearable-jansa-jethro-test-dependencies-qemux86/85/artifact/BUILD-ARTIFACTS/qemux86/2_max/failed/libconnman-qt5.log
PNBLACKLIST[libconnman-qt5] ?= "requires dbus module enabled in qtbase, which was disabled in PLAT-18268"
PNBLACKLIST[maliit-framework-qt5] ?= "maliit-framework-webos is preferred"
PNBLACKLIST[maliit-plugins-qt5] ?= "depends on blacklisted maliit-framework-qt5"

PNBLACKLIST[vlc] ?= "depends on blacklisted qt4-x11-free, libxpm, fluidsynth, libmad, mpeg2dec"
PNBLACKLIST[navit] ?= "depends on blacklisted qt4-x11-free"
PNBLACKLIST[gnuradio] ?= "depends on blacklisted qt4-x11-free"
PNBLACKLIST[clutter-box2d] ?= "depends on blacklisted clutter-1.8"
PNBLACKLIST[clutter-gst-1.8] ?= "depends on blacklisted clutter-1.8"
PNBLACKLIST[clutter-gtk-1.8] ?= "depends on blacklisted clutter-1.8"
PNBLACKLIST[mx] ?= "depends on blacklisted clutter-1.8, startup-notification, libxrandr"
PNBLACKLIST[xterm] ?= "depends on blacklisted libxpm, libxau, libxext, libxaw"
PNBLACKLIST[puzzles] ?= "depends on blacklisted libxt"
PNBLACKLIST[cogl-1.0] ?= "depends on non-existent libgles2"
PNBLACKLIST[clutter-1.0] ?= "depends on blacklisted cogl-1.0"
PNBLACKLIST[clutter-gst-1.0] ?= "depends on blacklisted clutter-1.0"
PNBLACKLIST[clutter-gst-3.0] ?= "depends on blacklisted clutter-1.0"
PNBLACKLIST[mx-1.0] ?= "depends on blacklisted clutter-1.0"
PNBLACKLIST[at-spi2-atk] ?= "depends on blacklisted at-spi2-core"
PNBLACKLIST[libfakekey] ?= "depends on blacklisted libxtst"
PNBLACKLIST[gtkmathview] ?= "depends on blacklisted t1lib"
PNBLACKLIST[pidgin] ?= "depends on blacklisted startup-notification"
PNBLACKLIST[pidgin-otr] ?= "depends on blacklisted pidgin"
PNBLACKLIST[matchbox-desktop] ?= "depends on blacklisted startup-notification"
PNBLACKLIST[matchbox-panel-2] ?= "depends on blacklisted startup-notification"
PNBLACKLIST[matchbox-keyboard] ?= "depends on blacklisted libxft"
PNBLACKLIST[matchbox-theme-sato] ?= "depends on blacklisted matchbox-wm"
PNBLACKLIST[pcmanfm] ?= "depends on blacklisted startup-notification"
PNBLACKLIST[libxcb] ?= "depends on blacklisted libxau, libxdmcp"
PNBLACKLIST[gtk+3] ?= "depends on blacklisted libxrandr, libxext, libxcursor, libxdamage, libxrender, libxcomposite, libxi"
PNBLACKLIST[fltk] ?= "depends on blacklisted libxext, libxft"
PNBLACKLIST[xserver-xorg] ?= "depends on blacklisted libxext"
PNBLACKLIST[xcursorgen] ?= "depends on blacklisted libxcursor"
PNBLACKLIST[xf86-input-synaptics] ?= "depends on blacklisted libxi"
PNBLACKLIST[xvideo-tests] ?= "depends on blacklisted libxv"
PNBLACKLIST[libdc1394] ?= "depends on blacklisted libxv"
PNBLACKLIST[xbitmaps] ?= "depends on blacklisted libxmu"
PNBLACKLIST[xcb-util] ?= "depends on blacklisted libxcb"
PNBLACKLIST[xcb-util-image] ?= "depends on blacklisted libxcb"
PNBLACKLIST[xcb-util-renderutil] ?= "depends on blacklisted libxcb"
PNBLACKLIST[xcb-util-wm] ?= "depends on blacklisted libxcb"
PNBLACKLIST[xcb-util-keysyms] ?= "depends on blacklisted libxcb"
PNBLACKLIST[xf86-input-mtev] ?= "depends on blacklisted xserver-xorg"
PNBLACKLIST[xf86-input-keyboard] ?= "depends on blacklisted xserver-xorg"
PNBLACKLIST[xf86-input-evdev] ?= "depends on blacklisted xserver-xorg"
PNBLACKLIST[xf86-video-fbdev] ?= "depends on blacklisted xserver-xorg"
PNBLACKLIST[xf86-input-mouse] ?= "depends on blacklisted xserver-xorg"
PNBLACKLIST[xf86-video-modesetting] ?= "depends on blacklisted xserver-xorg"
PNBLACKLIST[xf86-video-glamo] ?= "depends on blacklisted xserver-xorg"
PNBLACKLIST[xf86-input-void] ?= "depends on blacklisted xserver-xorg"
PNBLACKLIST[xf86-input-tslib] ?= "depends on blacklisted xserver-xorg"
PNBLACKLIST[xf86-input-vmmouse] ?= "depends on blacklisted xserver-xorg"
PNBLACKLIST[xf86-video-geode] ?= "depends on blacklisted xserver-xorg"
PNBLACKLIST[xf86-video-cirrus] ?= "depends on blacklisted xserver-xorg"
PNBLACKLIST[l3afpad] ?= "depends on blacklisted gtk+3"
PNBLACKLIST[libcanberra] ?= "depends on blacklisted gtk+3"
PNBLACKLIST[libnotify] ?= "depends on blacklisted gtk+3"
PNBLACKLIST[clutter-gtk-1.0] ?= "depends on blacklisted gtk+3"
PNBLACKLIST[gcr] ?= "depends on blacklisted gtk+3"
PNBLACKLIST[wayland-fits] ?= "depends on blacklisted gtk+3 and we have own wayland-fits-webos fork"
PNBLACKLIST[rygel] ?= "depends on blacklisted gtk+3"
PNBLACKLIST[wireshark] ?= "depends on blacklisted gtk+3"
PNBLACKLIST[midori] ?= "depends on blacklisted libnotify"
PNBLACKLIST[boinc-client] ?= "depends on blacklisted libnotify"
PNBLACKLIST[pavucontrol] ?= "depends on blacklisted libcanberra"
PNBLACKLIST[sato-screenshot] ?= "depends on blacklisted matchbox-panel-2"
PNBLACKLIST[networkmanager] ?= "depends on blacklisted polkit"
PNBLACKLIST[networkmanager-openvpn] ?= "depends on blacklisted networkmanager"
PNBLACKLIST[openlmi-networking] ?= "depends on blacklisted networkmanager and openlmi-providers"
PNBLACKLIST[openlmi-storage] ?= "depends on blacklisted openlmi-providers"
PNBLACKLIST[modemmanager] ?= "depends on blacklisted polkit"
PNBLACKLIST[geoclue] ?= "depends on blacklisted modemmanager"
PNBLACKLIST[upower] ?= "depends on blacklisted polkit"
PNBLACKLIST[devicekit-power] ?= "depends on blacklisted polkit"
PNBLACKLIST[udisks] ?= "depends on blacklisted polkit"
PNBLACKLIST[udisks2] ?= "depends on blacklisted polkit"
PNBLACKLIST[polkit-gnome] ?= "depends on blacklisted polkit"
PNBLACKLIST[packagekit] ?= "depends on blacklisted polkit"
PNBLACKLIST[polkit-group-rule-network] ?= "depends on blacklisted polkit"
PNBLACKLIST[polkit-group-rule-datetime] ?= "depends on blacklisted polkit"
PNBLACKLIST[xorg-cf-files] ?= "depends on blacklisted font-util"
PNBLACKLIST[encodings] ?= "depends on blacklisted mkfontscale-native"
PNBLACKLIST[imake] ?= "depends on blacklisted xorg-cf-files"
PNBLACKLIST[xdg-utils] ?= "depends on blacklisted xprop"
#PNBLACKLIST[] ?= "depends on blacklisted "

PNBLACKLIST[packagegroup-core-directfb] ?= "rdepends on blacklisted directfb, directfb-examples"
PNBLACKLIST[matchbox-session-sato] ?= "rdepends on blacklisted matchbox-theme-sato, matchbox-panel-2, matchbox-session-sato-dev"
PNBLACKLIST[anki] ?= "rdepends on blacklisted python-pyqt, python-sip"
PNBLACKLIST[polkit] ?= "rdepends on blacklisted consolekit"
PNBLACKLIST[xserver-common] ?= "rdepends on blacklisted xrandr, xinput-calibrator"
PNBLACKLIST[packagegroup-core-lsb] ?= "rdepends on blacklisted libqtcore4, libqtgui4, libqtsql4, libqtsvg4, libqtxml4, libqtnetwork4, libxt, libxxf86vm, libxi, libxtst, qt4-plugin-sqldriver-sqlite, libx11-locale, libqtopengl4, packagegroup-core-sys-extended, packagegroup-core-db, packagegroup-core-perl, packagegroup-core-python, packagegroup-core-tcl, packagegroup-core-lsb-misc, packagegroup-core-lsb-core, packagegroup-core-lsb-perl, packagegroup-core-lsb-python, packagegroup-core-lsb-desktop, packagegroup-core-lsb-runtime-add"
PNBLACKLIST[font-util] ?= "rdepends on blacklisted mkfontdir, mkfontscale"
PNBLACKLIST[font-alias] ?= "rdepends on blacklisted font-util"
PNBLACKLIST[packagegroup-core-standalone-gmae-sdk-target] ?= "rdepends on blacklisted libxi-dev, gnome-desktop"
PNBLACKLIST[packagegroup-core-tools-testapps] ?= "rdepends on blacklisted fstests, x11perf, xrestop, xwininfo, xprop, xvideo-tests"
PNBLACKLIST[xorg-minimal-fonts] ?= "rdepends on blacklisted font-alias"
PNBLACKLIST[zaurusd] ?= "rdepends on blacklisted xrandr"
PNBLACKLIST[packagegroup-core-sdk-gmae] ?= "rdepends on blacklisted libxi-dev, gnome-desktop"
PNBLACKLIST[xserver-nodm-init] ?= "rdepends on blacklisted xserver-common, xinit"
PNBLACKLIST[packagegroup-core-clutter] ?= "rdepends on blacklisted clutter-1.8, clutter-gst-1.8, clutter-gtk-1.8"
#PNBLACKLIST[] ?= "rdepends on blacklisted "

PNBLACKLIST[net-snmp] ?= "broken: net-snmp-5.7.2/agent/snmpd.c:459: undefined reference to `netsnmp_sd_listen_fds'"
PNBLACKLIST[emacs] ?= "broken: qemu dies while running qemu-treedir qemu: uncaught target signal 11 (Segmentation fault) - core dumped"
PNBLACKLIST[rpm] ?= "broken: rpm-5.4.9/rpmdb/.libs/librpmdb.so: undefined reference to `db3Free'"
PNBLACKLIST[mg] ?= "broken: Missing ncurses dependency: Looking for term.h...  Not found!"
PNBLACKLIST[gtk+] ?= "broken: cairo-xlib isn't availabe without x11 DISTRO_FEATURES: No package 'cairo-xlib' found"
PNBLACKLIST[ode] ?= "broken: configure:6512: error: cannot run test program while cross compiling"
PNBLACKLIST[libglu] ?= "broken: we don't build libGL with mesa: cannot find -lGL"
PNBLACKLIST[glmark2] ?= "broken: we don't build libGL with mesa: cannot find -lGL"
PNBLACKLIST[mesa-demos] ?= "broken: we don't build libGL with mesa"
# remove this when using libav from libav_git.bb which doesn't create libpostproc packages and DEPENDS on libpostproc
PNBLACKLIST[libpostproc] ?= "broken: conflicts with packages created by libav-0.8.4"
PNBLACKLIST[sox] ?= "depends on blacklisted libav (which has incompatible license)"
# cloud9 isn't compatible with 0.10 nodejs https://github.com/ajaxorg/cloud9/issues/2741
# proper fix would be to retain 0.8 version in nodejs8 (like we do with nodejs4_0.4.12) and update cloud9 dependency to nodejs8
PNBLACKLIST[cloud9] ?= "broken: isn't compatible with our nodejs"
PNBLACKLIST[libgc] ?= "replaced by bdwgc in oe-core"
PNBLACKLIST[zile] ?= "depends on blacklisted libgc"
PNBLACKLIST[mosh] ?= "depends on blacklisted protobuf"
PNBLACKLIST[protobuf-c] ?= "requires newer protobuf than what we have in meta-webos"
PNBLACKLIST[mongodb] ?= "depends on blacklisted gperftools"
PNBLACKLIST[gst-plugins-gl] ?= "depends on blacklisted glew"
PNBLACKLIST[openlmi-providers] ?= "sometimes fails with KonkretCMPI failed: 1 error: no such super class: CIM_ATAProtocolEndpoint http://caprica.lgsvl.com:8080/Errors/Details/914383"
PNBLACKLIST[poco] ?= "provides libCppUnit.so.1 sometimes in poco, sometimes in poco-cppunit package http://lists.openembedded.org/pipermail/openembedded-devel/2018-January/116573.html"
PNBLACKLIST[tiptop] ?= "Sometimes fails with calc.lex:75: error: undefined reference to 'yylval' http://caprica.lgsvl.com:8080/Errors/Details/909764"
PNBLACKLIST[paho-mqtt-c] ?= "Sometimes fails with cannot create build/VersionInfo.h: Directory nonexistent http://caprica.lgsvl.com:8080/Errors/Details/915077"

# cannot blacklist this, too many things depends on it
#PNBLACKLIST[ltrace] ?= "broken: error: 'BREAKPOINT_LENGTH' undeclared here (not in a function) "
#PNBLACKLIST[packagegroup-core-tools-debug] ?= "rdepends on broken ltrace"
#PNBLACKLIST[packagegroup-cli-tools] ?= "rdepends on broken ltrace"
#PNBLACKLIST[alsa-plugins] ?= "broken: alsa-plugins-1.0.26/a52/pcm_a52.c:412: undefined reference to `av_free'"
#PNBLACKLIST[] ?= "broken: "

PNBLACKLIST[pangomm] ?= "broken: missing dependency on pango with cairo enabled"
PNBLACKLIST[freerdp] ?= "broken: missing dependency on libX11 when gstreamer is enabled: http://caprica.lgsvl.com:8080/Errors/Details/873320"

PNBLACKLIST[rpmresolve] ?= "depends on broken rpm"
PNBLACKLIST[umip] ?= "depends on broken rpm"
PNBLACKLIST[python-smartpm] ?= "depends on broken rpm"
PNBLACKLIST[libgxim] ?= "depends on broken gtk+"
PNBLACKLIST[graphviz] ?= "depends on blacklisted gtk+,libglade,librsvg,mesa-glut"
PNBLACKLIST[imsettings] ?= "depends on broken gtk+"
PNBLACKLIST[gnome-themes-standard] ?= "depends on broken gtk+"
PNBLACKLIST[gtkperf] ?= "depends on broken gtk+"
PNBLACKLIST[gtk-sato-engine] ?= "depends on broken gtk+"
PNBLACKLIST[gegl] ?= "depends on broken gtk+"
PNBLACKLIST[libowl-av] ?= "depends on broken gtk+"
PNBLACKLIST[vala] ?= "depends on broken gtk+"
PNBLACKLIST[oh-puzzles] ?= "depends on broken gtk+"
PNBLACKLIST[connman-gnome] ?= "depends on broken gtk+"
PNBLACKLIST[subsurface] ?= "depends on broken gtk+"
PNBLACKLIST[librsvg] ?= "depends on broken gtk+"
PNBLACKLIST[gtk-engines] ?= "depends on broken gtk+"
PNBLACKLIST[vte] ?= "depends on broken gtk+"
PNBLACKLIST[obex-data-server] ?= "depends on broken gtk+"
PNBLACKLIST[poppler] ?= "depends on broken gtk+"
PNBLACKLIST[leafpad] ?= "depends on broken gtk+"
PNBLACKLIST[matchbox-terminal] ?= "depends on broken gtk+"
PNBLACKLIST[opencv] ?= "depends on broken gtk+"
PNBLACKLIST[libsexy] ?= "depends on broken gtk+"
PNBLACKLIST[geany] ?= "depends on broken gtk+"
PNBLACKLIST[geany-plugins] ?= "depends on broken gtk+, geany"
PNBLACKLIST[gtk-theme-torturer] ?= "depends on broken gtk+"
PNBLACKLIST[libowl] ?= "depends on broken gtk+"
PNBLACKLIST[gtkhtml2] ?= "depends on broken gtk+"
PNBLACKLIST[gaku] ?= "depends on broken gtk+"
PNBLACKLIST[kernelshark] ?= "depends on broken gtk+"
PNBLACKLIST[python-pygtk] ?= "depends on broken gtk+"
PNBLACKLIST[foxtrotgps] ?= "depends on broken gtk+"
PNBLACKLIST[sysprof] ?= "depends on broken gtk+"
PNBLACKLIST[gnome-keyring] ?= "depends on broken gtk+"
PNBLACKLIST[orrery] ?= "depends on broken gtk+"
PNBLACKLIST[settings-daemon] ?= "depends on broken gtk+"
PNBLACKLIST[glade3] ?= "depends on broken gtk+"
PNBLACKLIST[libunique] ?= "depends on broken gtk+"
PNBLACKLIST[omgps] ?= "depends on broken gtk+"
PNBLACKLIST[libglade] ?= "depends on broken gtk+"
PNBLACKLIST[avahi-ui] ?= "depends on broken gtk+"
PNBLACKLIST[sylpheed] ?= "depends on broken gtk+"
PNBLACKLIST[matchbox-config-gtk] ?= "depends on broken gtk+"
PNBLACKLIST[libwmf] ?= "depends on broken gtk+"
PNBLACKLIST[gtkmm] ?= "depends on broken gtk+"
PNBLACKLIST[xchat] ?= "depends on broken gtk+"
PNBLACKLIST[oprofileui] ?= "depends on broken gtk+"
PNBLACKLIST[libfm] ?= "depends on broken gtk+"
PNBLACKLIST[claws-mail] ?= "depends on broken gtk+"
PNBLACKLIST[icon-slicer] ?= "depends on broken gtk+"
PNBLACKLIST[gtkextra] ?= "depends on broken gtk+"
PNBLACKLIST[coriander] ?= "depends on broken gtk+"
PNBLACKLIST[gst-player] ?= "depends on broken gtk+"
PNBLACKLIST[uim] ?= "depends on broken gtk+"
PNBLACKLIST[libsdl] ?= "depends on broken libglu"
PNBLACKLIST[libsdl-ttf] ?= "depends on broken libsdl"
PNBLACKLIST[libsdl-image] ?= "depends on broken libsdl"

PNBLACKLIST[bdwgc] ?= "depends on static library from libatomics-ops which is blacklisted by webos_no_static_libraries.bbclass"
PNBLACKLIST[php] ?= "depends on static library libc-client.a which is blacklisted by webos_no_static_libraries.bbclass"
PNBLACKLIST[phoronix-test-suite] ?= "depends on blacklisted php"
PNBLACKLIST[qemu] ?= "depends on blacklisted libsdl"
PNBLACKLIST[libvncserver] ?= "depends on blacklisted libsdl"

PNBLACKLIST[initscripts] ?= "replaced with webos-initscripts"
PNBLACKLIST[lsbinitscripts] ?= "replaced with webos-initscripts"

# Depends on something blacklisted because the dependency was depending on something broken
PNBLACKLIST[vala-dbus-binding-tool] ?= "depends on blacklisted vala"
PNBLACKLIST[libgee] ?= "depends on blacklisted vala"
PNBLACKLIST[gupnp-av] ?= "depends on blacklisted vala"
PNBLACKLIST[gupnp] ?= "depends on blacklisted vala"
PNBLACKLIST[gssdp] ?= "depends on blacklisted vala"
PNBLACKLIST[gupnp-dlna] ?= "depends on blacklisted vala"
PNBLACKLIST[libsecret] ?= "depends on blacklisted vala"
PNBLACKLIST[dleyna-renderer] ?= "depends on blacklisted vala"
PNBLACKLIST[dleyna-core] ?= "depends on blacklisted vala"
PNBLACKLIST[gupnp-igd] ?= "depends on blacklisted vala"
PNBLACKLIST[dleyna-connector-dbus] ?= "depends on blacklisted vala"
PNBLACKLIST[dleyna-server] ?= "depends on blacklisted vala"
PNBLACKLIST[opencv-samples] ?= "depends on blacklisted opencv"
PNBLACKLIST[owl-video] ?= "depends on blacklisted libowl-av"
PNBLACKLIST[toscoterm] ?= "depends on blacklisted vte"
PNBLACKLIST[vala-terminal] ?= "depends on blacklisted vte"
PNBLACKLIST[imagemagick] ?= "depends on blacklisted librsvg"
PNBLACKLIST[guile] ?= "depends on blacklisted bdwgc"
PNBLACKLIST[claws-plugin-gtkhtml2-viewer] ?= "depends on blacklisted claws-mail"
PNBLACKLIST[claws-plugin-mailmbox] ?= "depends on blacklisted claws-mail"
PNBLACKLIST[claws-plugin-rssyl] ?= "depends on blacklisted claws-mail"
PNBLACKLIST[gupnp-tools] ?= "depends on blacklisted gtk+, gnome-icon-theme, gupnp-av, gtk+3"
PNBLACKLIST[media-service-upnp] ?= "rdepends on blacklisted python-gst, python-pygtk, gupnp-av, gupnp-dlna, gssdp"
PNBLACKLIST[gstreamer1.0-plugins-bad] ?= "depends on broken librsvg"
#PNBLACKLIST[] ?= "depends on blacklisted "

PNBLACKLIST[python-gst] ?= "rdepends on blacklisted python-pygtk"
PNBLACKLIST[gnome-icon-theme] ?= "rdepends on blacklisted librsvg-gtk"
#PNBLACKLIST[] ?= "rdepends on blacklisted "

PNBLACKLIST[enca] ?= "ERROR: QA Issue: enca: configure was passed unrecognised options: --with-libiconv-prefix [unknown-configure-option]"
PNBLACKLIST[corosync] ?= "ERROR: QA Issue: corosync: configure was passed unrecognised options: --disable-nss --enable-nss [unknown-configure-option]"
PNBLACKLIST[dlm] ?= "ERROR: Depends on blacklisted corosync"
PNBLACKLIST[libass] ?= "ERROR: Depends on blacklisted enca"

PNBLACKLIST[weston] ?= "Not compatible with old wayland used in webos-pro http://caprica.lgsvl.com:8080/Errors/Details/881250"
PNBLACKLIST[weston-init] ?= "depends on blacklisted weston"
PNBLACKLIST[mpd] ?= "depends on blacklisted mpg123"
PNBLACKLIST[eglinfo-fb] ?= "BROKEN: Checking for library ['GLESv2', 'EGL', 'bcm_host'] : not found http://caprica.lgsvl.com:8080/Errors/Details/887450"
PNBLACKLIST[grub] ?= "BROKEN: configure: error: could not force soft-float http://caprica.lgsvl.com:8080/Errors/Details/887455"
PNBLACKLIST[cryptodev-module] ?= "BROKEN for aarch64: cryptodev-module/1.8-r0/cryptodev-linux-1.8/zc.c:63:8: error: too many arguments to function 'get_user_pages_remote' http://caprica.lgsvl.com:8080/Errors/Details/887454"
PNBLACKLIST[initramfs-live-install] ?= "Runtime depends on blacklisted grub"
PNBLACKLIST[initramfs-live-install-testfs] ?= "Runtime depends on blacklisted grub"
PNBLACKLIST[android-tools] ?= "Fails to build with thumb enabled http://caprica.lgsvl.com:8080/Errors/Details/898924"
PNBLACKLIST[llvm] ?= "Fails to build for armv5 http://caprica.lgsvl.com:8080/Errors/Details/898925"

PNBLACKLIST[sysstat] ?= "BROKEN: install: invalid group ‘man’"
PNBLACKLIST[hplip] ?= "BROKEN: configure: error: could not force soft-float"

# Broken when aarch64 MACHINE is used
PNBLACKLIST[breakpad] ?= "BROKEN for aarch64: trunk/src/client/linux/dump_writer_common/thread_info.h:69:23: error: field 'regs' has incomplete type 'google_breakpad::user_pt_regs'"
PNBLACKLIST[cdparanoia] ?= "BROKEN for aarch64: checking host system type... Invalid configuration `aarch64-apollo-linux': machine `aarch64-apollo' not recognized"
PNBLACKLIST[iscsitarget] ?= "BROKEN for aarch64: aarch64-apollo-linux-ld: internal error in set_address, at ../../gold/output.h:322"
PNBLACKLIST[protobuf] ?= "BROKEN for aarch64: git/src/google/protobuf/stubs/once.h:143:23: error: 'ProtobufOnceType' in namespace 'google::protobuf' does not name a type"
PNBLACKLIST[thrift] ?= "BROKEN for aarch64: checking host system type... Invalid configuration `aarch64-apollo-linux': machine `aarch64-apollo' not recognized"
PNBLACKLIST[luajit] ?= "BROKEN for aarch64: lj_arch.h:55:2: error: #error \"No support for this architecture (yet)\""
PNBLACKLIST[a2jmidid] ?= "BROKEN for aarch64: ../sigsegv.c:95:20: error: 'NGREG' undeclared (first use in this function)"
PNBLACKLIST[kernel-devsrc] ?= "BROKEN for aarch64: make[4]: *** No rule to make target `/home/jenkins/anaconda/build-apollo-morty/build/BUILD/work/raspberrypi3_64-apollo-linux/kernel-devsrc/1.0-r0/image/usr/src/kernel/arch/arm64/boot/dts/broadcom/../overlays/Makefile'.  Stop"

PNBLACKLIST[packagegroup-cli-tools] ?= "Runtime depends on blacklisted sysstat"
PNBLACKLIST[sysdig] ?= "Depends on unavailable luajit"

PNBLACKLIST[lsbtest] ?= "rdepends on broken rpm"
#PNBLACKLIST[] ?= "rdepends on broken "

# upstream recipes with known QA issues
# /usr/bin/luajit-2.0.0, /usr/lib/libluajit-5.1.so.2.0.0
INSANE_SKIP_${PN}_pn-luajit = "already-stripped"
# /usr/lib/libx264.so.129
INSANE_SKIP_${PN}_pn-x264 = "textrel"
# /usr/bin/oscam
INSANE_SKIP_${PN}_pn-oscam = "already-stripped"

# Newer tesseract-lang is backported to meta-webos-backports-2.2, but old
# recipes conflicting with it are still available from meta-oe
PNBLACKLIST[tesseract-lang-dan] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-swe] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-heb] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-epo] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-tel] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-mkd] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-est] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-cat] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-kor] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-hun] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-ben] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-afr] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-vie] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-ces] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-spa-old] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-chi-sim] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-hin] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-rus] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-kan] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-eus] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-chi-tra] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-sqi] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-tha] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-ita-old] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-bul] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-tgl] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-ron] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-lav] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-ell] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-slv] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-jpn] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-epo-alt] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-bel] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-enm] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-lit] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-mal] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-aze] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-nor] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-glg] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-ukr] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-deu] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-fra] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-ind] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-isl] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-msa] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-tam] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-hrv] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-eng] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-ita] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-grc] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-ara] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-swa] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-slk] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-chr] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-por] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-pol] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-equ] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-spa] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-tur] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-mlt] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-frm] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-frk] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-fin] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-srp] ?= "Now provided by tesseract-lang recipe"
PNBLACKLIST[tesseract-lang-nld] ?= "Now provided by tesseract-lang recipe"

INSANE_SKIP_${PN}-audio_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-codecs_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-core_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-crypt_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-ctypes_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-curses_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-fcntl_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-gdbm_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-io_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-json_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-lang_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-math_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-misc_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-mmap_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-multiprocessing_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-profile_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-readline_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-resource_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-syslog_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-textutils_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-unixadmin_append_pn-python3 = " textrel"
INSANE_SKIP_${PN}-xml_append_pn-python3 = " textrel"

INSANE_SKIP_libgles1-mesa_append_pn-mesa = " textrel"
INSANE_SKIP_libgles2-mesa_append_pn-mesa = " textrel"
INSANE_SKIP_libglapi_append_pn-mesa = " textrel"

# Skip ldflags check for now
INSANE_SKIP_${PN}_append_pn-alljoyn = " ldflags"
INSANE_SKIP_${PN}_append_pn-aoetools = " ldflags"
INSANE_SKIP_${PN}_append_pn-canopensocket = " ldflags"
INSANE_SKIP_${PN}_append_pn-cdparanoia = " ldflags"
INSANE_SKIP_${PN}_append_pn-crash = " ldflags"
INSANE_SKIP_${PN}_append_pn-crda = " ldflags"
INSANE_SKIP_${PN}_append_pn-daemonize = " ldflags"
INSANE_SKIP_${PN}_append_pn-daemontools = " ldflags"
INSANE_SKIP_libdvbapi_append_pn-dvb-apps = " ldflags"
INSANE_SKIP_libdvbcfg_append_pn-dvb-apps = " ldflags"
INSANE_SKIP_libdvben50221_append_pn-dvb-apps = " ldflags"
INSANE_SKIP_libdvbsec_append_pn-dvb-apps = " ldflags"
INSANE_SKIP_libesg_append_pn-dvb-apps = " ldflags"
INSANE_SKIP_libucsi_append_pn-dvb-apps = " ldflags"
INSANE_SKIP_${PN}_append_pn-etcpak = " ldflags"
INSANE_SKIP_libflite-alsa-vox16_append_pn-flite-alsa = " ldflags"
INSANE_SKIP_libflite-alsa-vox8_append_pn-flite-alsa = " ldflags"
INSANE_SKIP_libflite-alsa_append_pn-flite-alsa = " ldflags"
INSANE_SKIP_${PN}-gpsctl_append_pn-gpsd = " ldflags"
INSANE_SKIP_libgps_append_pn-gpsd = " ldflags"
INSANE_SKIP_libgpsd_append_pn-gpsd = " ldflags"
INSANE_SKIP_${PN}_append_pn-gradm = " ldflags"
INSANE_SKIP_${PN}_append_pn-ifenslave = " ldflags"
INSANE_SKIP_${PN}_append_pn-iptraf = " ldflags"
INSANE_SKIP_${PN}_append_pn-ipvsadm = " ldflags"
INSANE_SKIP_${PN}_append_pn-iscsitarget = " ldflags"
INSANE_SKIP_${PN}_append_pn-libmatroska = " ldflags"
INSANE_SKIP_${PN}_append_pn-libx86-1 = " ldflags"
INSANE_SKIP_${PN}_append_pn-lio-utils = " ldflags"
INSANE_SKIP_${PN}_append_pn-log4cpp = " ldflags"
INSANE_SKIP_${PN}_append_pn-logfsprogs = " ldflags"
INSANE_SKIP_kpartx_append_pn-multipath-tools = " ldflags"
INSANE_SKIP_${PN}_append_pn-multipath-tools = " ldflags"
INSANE_SKIP_${PN}_append_pn-nginx = " ldflags"
INSANE_SKIP_${PN}_append_pn-nuttcp = " ldflags"
INSANE_SKIP_${PN}_append_pn-openl2tp = " ldflags"
INSANE_SKIP_${PN}_append_pn-pam-passwdqc = " ldflags"
INSANE_SKIP_${PN}_append_pn-picocom = " ldflags"
INSANE_SKIP_${PN}_append_pn-pngcheck = " ldflags"
INSANE_SKIP_${PN}_append_pn-procmail = " ldflags"
INSANE_SKIP_${PN}_append_pn-pycd = " ldflags"
INSANE_SKIP_${PN}_append_pn-qtchooser = " ldflags"
INSANE_SKIP_${PN}_append_pn-qtwebengine = " ldflags"
INSANE_SKIP_${PN}-examples_append_pn-qtwebengine = " ldflags"
INSANE_SKIP_${PN}-qmlplugins_append_pn-qtwebengine = " ldflags"
INSANE_SKIP_${PN}_append_pn-rtmpdump = " ldflags"
INSANE_SKIP_${PN}_append_pn-sgpio = " ldflags"
INSANE_SKIP_${PN}_append_pn-smstools3 = " ldflags"
INSANE_SKIP_${PN}_append_pn-suspend-blocker = " ldflags"
INSANE_SKIP_${PN}_append_pn-system-setup-keyboard = " ldflags"
INSANE_SKIP_${PN}_append_pn-testfloat = " ldflags"
INSANE_SKIP_${PN}_append_pn-tinymembench = " ldflags"
INSANE_SKIP_${PN}_append_pn-tsocks = " ldflags"
INSANE_SKIP_${PN}_append_pn-tunctl = " ldflags"
INSANE_SKIP_${PN}_append_pn-uml-utilities = " ldflags"
INSANE_SKIP_${PN}_append_pn-vblade = " ldflags"
INSANE_SKIP_${PN}_append_pn-wipe = " ldflags"
INSANE_SKIP_${PN}_append_pn-yaffs2-utils = " ldflags"
INSANE_SKIP_${PN}_append_pn-zeroconf = " ldflags"
