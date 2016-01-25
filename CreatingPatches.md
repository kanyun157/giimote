# Introduction #

GiiMote is an open source project and user contributions are welcome in the form of patches. Patch files are small, portable, ".diff" files which describe all of the changes the developer has made to the source code. These files can then be reviewed and merged with the project. If you do not have access to the repository you should use patches to submit your changes.


# Creating a patch #

To create a patch first [download and build](BuildDocumentation.md) GiiMote. After you are sure GiiMote compiles correctly make and test your changes. Once your changes compile correctly, are bug-free, and follow the appropriate [coding conventions](CodingStyles.md) you can navigate to the root directory of the project and execute the following command to see a list of all changes:

```
hg log
```

To create the actual patch you can then run:

```
hg export 2 > changeset2.diff
```

This would export changeset 2. Make sure you are in the root directory when you create your diff file and that you give the file a descriptive name.


# Submitting a patch #

Once you've created and tested a patch you can submit it for inclusion in the main source tree. To do so visit the [Issues List](http://code.google.com/p/giimote/issues/list) and either attach the path to a relevant issue or create a new issue detailing the bug fix, feature, or other modification you have made. Please describe the changes you made to the code in detail in your report and apply the label "Type-Patch" to your issue. _DO NOT_ copy the contents of your diff file into the description box, always submit patches as an attachment. Finally, Cc yourself on the issue and you will be notified when your patch is accepted or if further modifications are needed.


# Links #

  * [Issues List](http://code.google.com/p/giimote/issues/list)