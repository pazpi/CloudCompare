//##########################################################################
//#                                                                        #
//#                            CLOUDCOMPARE                                #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 of the License.               #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#          COPYRIGHT: EDF R&D / TELECOM ParisTech (ENST-TSI)             #
//#                                                                        #
//##########################################################################

#ifndef CC_COLOR_SCALE_EDITOR_DLG_HEADER
#define CC_COLOR_SCALE_EDITOR_DLG_HEADER

#include <ui_colorScaleEditorDlg.h>

//local
#include "ccColorScaleEditorWidget.h"

//qCC_db
#include <ccColorScale.h>

//Qt
#include <QDialog>

class ccScalarField;
class ccColorScalesManager;

//! Dialog to edit/create color scales
class ccColorScaleEditorDialog : public QDialog, public Ui::ColorScaleEditorDlg
{
	Q_OBJECT

public:

	//! Default constructor
	ccColorScaleEditorDialog(ccColorScalesManager* manager, ccColorScale::Shared currentScale = ccColorScale::Shared(0), QWidget* parent = 0);

	//! Destructor
	virtual ~ccColorScaleEditorDialog();

	//! Sets associated scalar field (optional)
	void setAssociatedScalarField(ccScalarField* sf);

	//! Sets active scale
	void setActiveScale(ccColorScale::Shared currentScale);

	//! Returns active scale
	ccColorScale::Shared getActiveScale() { return m_colorScale; }

protected slots:

	void colorScaleChanged(int);
	void relativeModeChanged(int);

	void onStepSelected(int);

	void onStepModified(int);

	void deletecSelectedStep();

	void changeSelectedStepColor();

	void changeSelectedStepValue(double);

	void copyCurrentScale();
	void saveCurrentScale();
	void deleteCurrentScale();
	void renameCurrentScale();

	void exportCurrentScale();
	void importScale();

	void createNewScale();

	void onClose();

protected:

	//! Updates main combox box with color scales manager
	void updateMainComboBox();

	//! Sets modification flag state
	void setModified(bool state);

	//! If the current scale has been modified, ask the user what to do
	/** \return whether user allows the change or not
	**/
	bool canChangeCurrentScale();

	//! Returns whether current edited scale is 'relative' (true) or 'absolute' (false)
	/** Warning: may not be the same state as the current scale (m_colorScale)
		If current modifications have not been saved yet!
	**/
	bool isRelativeMode() const;

	//! Sets current mode for active scale between 'relative' (true) or 'absolute' (false)
	/** Warning: may not be the same state as the current scale (m_colorScale)
		If current modifications have not been saved yet!
	**/
	void setScaleModeToRelative(bool isRelative);

	//! Color scale manager
	ccColorScalesManager* m_manager;

	//! Current active color scale
	ccColorScale::Shared m_colorScale;

	//! Color scale editor widget
	ccColorScaleEditorWidget* m_scaleWidget;

	//! Associated scalar field
	ccScalarField* m_associatedSF;

	//! Modification flag
	bool m_modified;

	//! Current min boundary for absolute scales
	double m_minAbsoluteVal;
	//! Current max boundary for absolute scales
	double m_maxAbsoluteVal;
};

#endif //CC_COLOR_SCALE_EDITOR_DLG_HEADER
