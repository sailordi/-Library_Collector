#ifndef BUILDDATAWIDGET_H
#define BUILDDATAWIDGET_H

#include "Base/LayoutWidget/MultiLayoutWidget.h"

#include <QSharedDataPointer>

class QLineEdit;
class QTextEdit;
class QPushButton;

class BuildData;

/*! \class BuildDataWidget
 * \brief The class contains widgets for adding/updating the build data
 *
 * Incudes: MultiLayoutWidget & QSharedDataPointer
 *
 * Forward declarations: QLineEdit, QTextEdit & QPushButton
 *
 * Inherits: MultiLayoutWidget
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2020-06-11
 * \date Last update: 2020-06-11
*/
class BuildDataWidget : public MultiLayoutWidget
{
    Q_OBJECT
public:
    /*! Constructor
     * \param l - The layout for the build data widgets
     * \param parent - The parent [Default: nullptr]
    */
    explicit BuildDataWidget(QGridLayout* l,QWidget *parent = nullptr);

    /*! Sets the old data pointer
     * \param data - The pointer to the data
    */
    void setOldData(QSharedPointer<BuildData> data);
    /*! Setes the build name
     * \param buildName - The build name
    */
    void setBuildName(QString buildName);
    /*! Sets the debug path
     * \param debugPath
    */
    void setDebugPath(QString debugPath);
    /*! Sets the release path
     * \param releasePath
    */
    void setReleasePath(QString releasePath);

    /*! Updates the old data with the new data */
    void updateOldData();
    /*! Returns the build name
     * \param QString
    */
    QString buildName();
    /*! Returns the debug path
     * \param QString
    */
    QString debugPath();
    /*! Returns the release
     * \param QString
    */
    QString releasePath();

    /*! Returns the debug path selection button
     * \param QPushButton*
    */
    QPushButton* debugPathButton();
    /*! Returns the release path selection button
     * \param QPushButton*
    */
    QPushButton* releasePathButton();

    /*! Hides/shows the reset buttons
     * \param hide - If the buttuns should be hidden
    */
    void hideResetButtons(bool hide);

    /*! Clears all the data
     * \param onlyText - If only the text should be cleared
    */
    void clear(bool onlyText);

private:
    QLineEdit* v_buildNameE = nullptr;
    QTextEdit* v_debugPathE = nullptr,*v_releasePathE = nullptr;
    QPushButton* v_debugPathB = nullptr,*v_releasePathB = nullptr;
    QPushButton* v_resetBuildNameB = nullptr,*v_resetDebugPathB = nullptr,*v_resetReleasePathB = nullptr;

    QSharedPointer<BuildData> v_oldBuildData;

    /*! Initializes widgets that are used */
    void init();

};
#endif // BUILDDATAWIDGET_H
