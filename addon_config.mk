# All variables and this file are optional, if they are not present the PG and the
# makefiles will try to parse the correct values from the file system.
#
# Variables that specify exclusions can use % as a wildcard to specify that anything in
# that position will match. A partial path can also be specified to, for example, exclude
# a whole folder from the parsed paths from the file system
#
# Variables can be specified using = or +=
# = will clear the contents of that variable both specified from the file or the ones parsed
# from the file system
# += will add the values to the previous ones in the file or the ones parsed from the file 
# system
# 
# The PG can be used to detect errors in this file, just create a new project with this addon 
# and the PG will write to the console the kind of error and in which line it is

meta:
	ADDON_NAME = ofxVboSet
	ADDON_DESCRIPTION = wrapper of ofVbo
	ADDON_AUTHOR = Nobuhiro.Saijo
	ADDON_TAGS = "tool"
	# ADDON_URL = http://github.com/openframeworks/openFrameworks

common:
	# dependencies with other addons, a list of them separated by spaces 
	# or use += in several lines
	# ここに追記するとPGで自動追加されると良いな、と思いますが、実際には使われていない様子。
	# parseされたdataは、std::vector<std::string> ofAddon::dependeincies に突っ込まれるようだ。
	# ADDON_DEPENDENCIES = ofxOsc
	# ADDON_DEPENDENCIES +=
	
	# include search paths, this will be usually parsed from the file system
	# but if the addon or addon libraries need special search paths they can be
	# specified here separated by spaces or one per line using +=
	# Xcode : Build Settings > Header Search Paths
	# 除外したい場合は ADDON_INCLUDES_EXCLUDE に追加。
	# EXCLUDE中の%はワイルドカードとして機能する。
	#	例)
	#	common:
	#	ADDON_INCLUDES  = libs/hoge/includes
	#	ADDON_INCLUDES += libs/fuga/includes
	#	
	#	osx:
	#	ADDON_INCLUDES_EXCLUDE  = libs/fuga/includes/win32
	#	ADDON_INCLUDES_EXCLUDE += libs/fuga/includes/win64
	# ADDON_INCLUDES = libs/lib_Sample_dotA/includes
	# ADDON_INCLUDES += libs/lib_Sample_dylib/includes
	
	# any special flag that should be passed to the compiler when using this addon
	# cファイルのコンパイル時に付けるフラグ
	# XcodeだとBuild Settings > Other C Flagsに追加される
	# ADDON_CFLAGS =
	
	# cppファイルのコンパイル時に付けるフラグ
	# XcodeだとBuild Settings > Other C++ Flagsに追加される
	# ADDON_CPPFLAGS = 
	
	# any special flag that should be passed to the linker when using this
	# addon, also used for system libraries with -lname
	# ldに付けるフラグ
	# ADDON_LDFLAGS = -Xlinker -rpath -Xlinker @executable_path ってやるとmacとかで幸せになれるかも
	# XcodeだとBuild Settings > Other Linker Flagsに追加される
	#
	#	@rpathってなんだ？
	#		http://blog.livedoor.jp/tana000/archives/1984267.html
	#
	#	macOSのコマンドラインアプリでdylibをよろしく扱う方法
	#		https://qiita.com/omochimetaru/items/21d662b8df8bce1bc5ca
	#	
	#	dyld: Library not loaded: @rpath/libdarknetOSX.dylib #3
	#		https://github.com/schwittlick/ofxDarknet/issues/3
	#	
	#	Trouble with dylib’s
	#		https://forum.openframeworks.cc/t/trouble-with-dylibs/32507/9
	#
	# ADDON_LDFLAGS = -rpath @loader_path/../../../../../../../addons/ofxOsc_BiDirection_Sample/libs/lib_Sample_dylib/lib/osx
	
	
	# ADDON_LIBS / ADDON_LIBS_EXCLUDE
	# 外部ライブラリを追加するために使う
	# libhoge.a とか libhoge.dylib とかを記述する
	# XcodeだとBuild Settings > Other Linker Flagsに追加される
	# 除外したいファイルはEXCLUDEに
	# EXCLUDE中の%はワイルドカードとして機能する
	# ADDON_LIBS = 

	# linux only, any library that should be included in the project using
	# pkg-config
	# Linux用のようだ。
	# ADDON_PKG_CONFIG_LIBRARIES =
	
	# osx/iOS only, any framework that should be included in the project
	# OSX, iOS用
	# .frameworkを追加する.
	# ADDON_FRAMEWORKS =
	
	# source files, these will be usually parsed from the file system looking
	# in the src folders in libs and the root of the addon. if your addon needs
	# to include files in different places or a different set of files per platform
	# they can be specified here
	# ADDON_SOURCES/ ADDON_SOURCES_EXCLUDE
	# プロジェクトのソースファイルとして追加される
	# 追加したくない場合はADDON_SOURCES_EXCLUDEに指定する
	# EXCLUDE中の%はワイルドカードとして機能する
	# ADDON_SOURCES = libs/lib_Sample/src/sj_sample.cpp
	ADDON_SOURCES_EXCLUDE = libs/lib_Sample/src/sj_sample.h
	
	# ADDON_HEADER_SOURCES / ADDON_OBJC_SOURCES / ADDON_CPP_SOURCES
	# ADDON_SOURCES も拡張子でタイプは調べてくれてるので多分そんなに使わない
	
	# some addons need resources to be copied to the bin/data folder of the project
	# specify here any files that need to be copied, you can use wildcards like * and ?
	# プロジェクトのbin/dataにコピーする
	# ためのタグだと思うけど何も使われてないっぽい
	# パースされたデータは std::vector<std::string> ofAddon::data に突っ込まれる
	# ADDON_DATA = 
	
	# ADDON_DLLS_TO_COPY
	# windows用
	# dllをbinに追加
	
	# ADDON_DEFINES
	# defineマクロを定義する
	# XcodeだとBuild Settings > Preprocessor Macrosに追加される

linux:
linux64:
msys2:
	# when parsing the file system looking for sources exclude this for all or
	# a specific platform
	# ADDON_SOURCES_EXCLUDE = libs/oscpack/src/ip/posix/%
	
MinGW:
vs:
	# when parsing the file system looking for sources exclude this for all or
	# a specific platform
	# ADDON_SOURCES_EXCLUDE = libs/oscpack/src/ip/posix/%
	
win + visual studio:
linuxarmv6:
linuxarmv7:
android/armeabi:
Android ARM v5:
android/armeabi-v7a:
Android ARM v7:
android/x86:
emscripten:
ios:
osx:
	# ADDON_LIBS / ADDON_LIBS_EXCLUDE
	# 外部ライブラリを追加するために使う(.a)
	# dylibは、実行時linkなので書かない(書くと実行時にErrorが出てしまった)。
	# XcodeだとBuild Settings > Other Linker Flagsに追加される
	# 除外したいファイルはEXCLUDEに
	# EXCLUDE中の%はワイルドカードとして機能する
	# ADDON_LIBS = libs/lib_Sample_dotA/lib/osx/libsj_dotA.a
	# ADDON_LIBS += libs/lib_Sample_dylib/lib/osx/libsj_dylib.dylib
	# ADDON_LIBS = libs/lib_Sample_dotA/lib/osx/libsj_dotA.a
