# Introduction #

Building GiiMote from source is fairly pain free. The build process relies on many different tools, some of which must be installed and configured separately from GiiMote. The only recommended (and only supported) environments for building GiiMote are [Visual Studio](http://msdn.microsoft.com/en-us/vstudio/default.aspx) and [Visual C++ Express](http://www.microsoft.com/express/vc/).


# Getting the source #
There are several different ways to get the source.

## Tarball ##

A source tarball is available over HTTP and can be found by searching on the [downloads page](http://code.google.com/p/giimote/downloads/list?can=1&q=.tar.gz).

## Mercurial ##

You can also checkout a working copy of GiiMote from the [HG repository](https://giimote.googlecode.com/hg). To get a working copy from mercurial please follow the instructions on [this page](http://code.google.com/p/giimote/source/checkout).

If you obtain the source from HG GiiMote may not be stable, or even compile at all. To get a copy of a stable release please checkout using one of these [tags](https://giimote.googlecode.com/hg/.hgtags).

## Browse source on the Web ##

If you merely want to look over the source code or download individual files you can browse the source code on the web by visiting [this page](http://code.google.com/p/giimote/source/browse/). You can also access the HG repository over http[s](s.md) [here](https://giimote.googlecode.com/hg/).


# Build prerequisites #

Before you attempt to build GiiMote make sure you have the proper tools and that they are configured correctly and visible to your build environment.

## Release ##
These dependencies are only used when you build GiiMote with the [release configuration](ReleaseConfiguration.md). This configuration does not embed debugging symbols and exports a source tarball after the build.

  * [Mercurial](Mercurial.md)
  * [Tar](Tar.md)
  * [Gzip](Gzip.md)

## Debug ##
The [debug configuration](DebugConfiguration.md) does not have any configuration-specific dependencies.

## MATLAB ##
To build GiiMote for [MATLAB](MATLAB.md) you must own a licensed copy of MATLAB. To find out more visit [The MathWorks](http://www.mathworks.com/).

## All Configurations ##

  * [.NET Framework](NetFramework.md)
  * [WiimoteLib](WiimoteLib.md)
  * [TlbExp](TlbExp.md)


# Build #

After you have all of your tools configured and the source downloaded you can finally build GiiMote. A solution for Visual Studio or Visual C++ Express is provided with the source. This is the recommended and only supported method for building GiiMote. Building in Visual Studio or Visual C++ Express is as easy as opening [GiiMote.sln](http://code.google.com/p/giimote/source/browse/trunk/GiiMote.sln) in the IDE, selecting a configuration ("[Release](ReleaseConfiguration.md)", "[Debug](DebugConfiguration.md)", or "[MATLAB](MatlabConfiguration.md)"), and pressing build.


# Links #

  * [Code browser](http://code.google.com/p/giimote/source/browse/)
  * [HG repo](https://giimote.googlecode.com/hg/)