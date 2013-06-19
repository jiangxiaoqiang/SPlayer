/* 
 *	Copyright (C) 2003-2006 Gabest
 *	http://www.gabest.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *   
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *   
 *  You should have received a copy of the GNU General Public License
 *  along with GNU Make; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. 
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#pragma once


interface __declspec(uuid("EE6F2741-7DB4-4AAD-A3CB-545208EE4C0A")) IBaseMuxerRelatedPin : public IUnknown
{
	STDMETHOD(SetRelatedPin) (CBasePin* pPin) = 0;
	STDMETHOD_(CBasePin*, GetRelatedPin) () = 0;
};

class CBaseMuxerRelatedPin : public IBaseMuxerRelatedPin
{
	CBasePin* m_pRelatedPin; // should not hold a reference because it would be circular

public:
	CBaseMuxerRelatedPin();
	virtual ~CBaseMuxerRelatedPin();

	// IBaseMuxerRelatedPin

	STDMETHODIMP SetRelatedPin(CBasePin* pPin);
	STDMETHODIMP_(CBasePin*) GetRelatedPin();
};