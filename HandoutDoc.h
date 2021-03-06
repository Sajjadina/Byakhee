// HandoutDoc.h : interface of the CHandoutDoc class
//
/////////////////////////////////////////////////////////////////////////////
/**
 * Copyright (C) 1998  David Harvey
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#if !defined(AFX_HANDOUTDOC_H__50F06ACF_F7F0_11D1_89C0_00001C192944__INCLUDED_)
#define AFX_HANDOUTDOC_H__50F06ACF_F7F0_11D1_89C0_00001C192944__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define MAX_HANDOUT_TEXT_FIELDS 50
#define MAX_HANDOUT_PICTURE_FIELDS 5

#include <afxtempl.h>

class CHandoutDoc : public CDocument
{
protected: // create from serialization only
	CHandoutDoc();
	DECLARE_DYNCREATE(CHandoutDoc)

// Attributes
public:
    CString m_strStrings[MAX_HANDOUT_TEXT_FIELDS];
    CString m_strPictures[MAX_HANDOUT_PICTURE_FIELDS];
    CString m_strSheet;

// Operations
public:
    //redefine these in public so that the view can get to them
	afx_msg void OnEditRedo();
	afx_msg void OnUpdateEditRedo(CCmdUI* pCmdUI);
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI* pCmdUI);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHandoutDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	void StoreUndo();
	virtual ~CHandoutDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	BOOL ParseHandoutSection( CString& strSection );
	//{{AFX_MSG(CHandoutDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

    struct HandoutUndoRedoData {
        CString m_strUndoStrings[MAX_HANDOUT_TEXT_FIELDS];
        CString m_strUndoPictures[MAX_HANDOUT_PICTURE_FIELDS];
    };
	CList<HandoutUndoRedoData, HandoutUndoRedoData&> m_UndoList;
	CList<HandoutUndoRedoData, HandoutUndoRedoData&> m_RedoList;

private:
	void DuplicateStringArray( CString* pDestination, CString* pSource, int nItems );
	CString BuildKeyPair( CString strName, int nValue );
	CString BuildKeyPair( CString strName, CString strValue );
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HANDOUTDOC_H__50F06ACF_F7F0_11D1_89C0_00001C192944__INCLUDED_)
