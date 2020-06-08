#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class WindowMain; }
QT_END_NAMESPACE

class LibraryDataWidget;
class NoticeAdapter;

/*! \class WindowMain
 * \brief The class is the main ui for the ptogram
 *
 * Incudes: QMainWindow
 *
 * Forward declarations: LibraryDataWidget
 *
 * Inherits: QMainWindow
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2020-06-06
 * \date Last update: 2020-06-06
*/
class WindowMain : public QMainWindow
{
    Q_OBJECT
public:
    /*! Constructor
     * \param parent - The windows parent [Default: nullptr]
    */
    explicit WindowMain(QWidget *parent = nullptr);
    /*! Deconstructor */
    ~WindowMain();

private slots:
    /*! Slot that is activated when output path selection button is clicked */
    void libraryOutPathBtnClicked();

    /*! Slot that is activated when header path selection button is clicked */
    void libraryHeaderPathBtnClicked();

    /*! Slot that is activated when debug build path selection button is clicked */
    void libraryDebugPathBtnClicked();
    /*! Slot that is activated when releas build path selection button is clicked */
    void libraryReleasePathBtnClicked();

    /*! Slot that is activated when preform collection button is clicked */
    void preformCollectionBtnClicked();

private:
    Ui::WindowMain* v_ui = nullptr;

    LibraryDataWidget* v_outDataW = nullptr,*v_headerDataW = nullptr;
    LibraryDataWidget* v_debugDataW = nullptr,*v_releaseDataW = nullptr;

    NoticeAdapter* v_noticeA = nullptr;

    /*! Saves the windows settings */
    void saveWindowSettings();

};
#endif // WINDOWMAIN_H
