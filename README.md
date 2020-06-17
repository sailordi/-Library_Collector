# Library_Collector
A program that collects library files into one folder in the same folder hierarchy as the library

The program collects .h files into a folder named includes in the output folder in the same folder hierarchy as in the header folder.

The program collects .a,.dll and .lib files into a folder named lib in the output folder from the release / debug build folder or both folders. 

## V1:
```
Created the project
Created the class Collector collects the nessesery info it is copied from one path into another
Added ui elements the WindowMain ui will need
Added slots that are needed in the WindowMain
Added comments to the constructor and deconstructor in WindowMain
```
## V2:
```
Added libraries that will be used in the project
Created the class LibraryDataWidget contains library data and handles the widgets
Created the class MessageHandler handles all messages
Created the class NoticeAdapter is an adapter against a NoticePage and the WindowNotice
Updated the ui with menu items for saving / loading the programs data
Added function that saves the window settings
Added function that loads the window setting
Added slot that will save the programs data
Added slot that will load the programs data
```
## V3:
```
Updated what library version the program is using 
Updated the ui
Created the class BuildData contains the builds name, relese path and debug path
Removed the LibraryDataWidget
Created the class MainInfoWidget that contains widgets for the main info layout [output path,header path & library base name]
Created the class BuildDataWidget it contains widgets for adding/updating the build data [build name, debug path & release path]
Created the class TextWrapDelegate is a delegate that allows text wrapping in a view
Created the class PathItemCreator is used for creating QStandardItems specific for path data
Created the class BuildDataTreeViewAdapter is an adapter against a QTreeView without child rows for the build data
Created the class BuildDataViewWidget that has widgets for the build data view
Added and updated functions that checks for errors and creates messages 
Updated the min window to use the new widgets
Added stot that is activated when add/update button is clicked
Added a slot that is activated when the cancel update button is clicked
Added a slot that is activated when update selected build data menu item is clicked
Added a slot that is activated when remove selected build data menu item is clicked
```