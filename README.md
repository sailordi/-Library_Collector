# Library_Collector
A program that collects library files into one folder in the same folder hierarchy as the library

The program collects .h files into a folder named includes in the output folder in the same folder hierarchy as in the header folder.

The program collects .a,.dll and .lib files into a folder named lib in the output folder from the release / debug build folder or both folders. 

## V1:
```
Created the project
Created the class Collector
Added ui elements the WindowMain ui will need
Added slots that are needed in the WindowMain
Added comments to the constructor and deconstructor in WindowMain
```
## V2:
```
Added libraries that will be used in the project
Created the class LibraryDataWidget
Created the class MessageHandler
Created the class NoticeAdapter
Updated the ui with menu items for saving / loading the programs data
Added function that saves the window settings
Added function that loads the window setting
Added slot that will save the programs data
Added slot that will load the programs data
```