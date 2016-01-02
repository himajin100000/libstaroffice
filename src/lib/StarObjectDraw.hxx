/* -*- Mode: C++; c-default-style: "k&r"; indent-tabs-mode: nil; tab-width: 2; c-basic-offset: 2 -*- */

/* libstaroffice
* Version: MPL 2.0 / LGPLv2+
*
* The contents of this file are subject to the Mozilla Public License Version
* 2.0 (the "License"); you may not use this file except in compliance with
* the License or as specified alternatively below. You may obtain a copy of
* the License at http://www.mozilla.org/MPL/
*
* Software distributed under the License is distributed on an "AS IS" basis,
* WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
* for the specific language governing rights and limitations under the
* License.
*
* Major Contributor(s):
* Copyright (C) 2002 William Lachance (wrlach@gmail.com)
* Copyright (C) 2002,2004 Marc Maurer (uwog@uwog.net)
* Copyright (C) 2004-2006 Fridrich Strba (fridrich.strba@bluewin.ch)
* Copyright (C) 2006, 2007 Andrew Ziem
* Copyright (C) 2011, 2012 Alonso Laurent (alonso@loria.fr)
*
*
* All Rights Reserved.
*
* For minor contributions see the git repository.
*
* Alternatively, the contents of this file may be used under the terms of
* the GNU Lesser General Public License Version 2 or later (the "LGPLv2+"),
* in which case the provisions of the LGPLv2+ are applicable
* instead of those above.
*/

/*
 * Parser to convert StarOffice's draw
 *
 */
#ifndef STAR_OBJECT_DRAW
#  define STAR_OBJECT_DRAW

#include <vector>
#include <string>

#include "libstaroffice_internal.hxx"

#include "StarObject.hxx"

namespace StarObjectDrawInternal
{
struct State;
}

class StarObject;
class StarZone;

/** \brief the main class to read a StarOffice draw
 *
 * \note currently, it contains only static function :-~
 *
 */
class StarObjectDraw : public StarObject
{
public:
  //! constructor
  StarObjectDraw(StarObject const &orig, bool duplicateState);
  //! destructor
  virtual ~StarObjectDraw();
  //! try to parse the current object
  bool parse();
  //! try to read a SdrModel zone: "DrMd"
  static bool readSdrModel(StarZone &zone, StarObject &doc);

protected:
  //! try to read a spreadsheet zone: StarDrawDocument .sdd
  bool readDrawDocument(STOFFInputStreamPtr input, std::string const &fileName);
  //! try to read a draw style zone: SfxStyleSheets
  bool readSfxStyleSheets(STOFFInputStreamPtr input, std::string const &fileName);

  //! try to read a SdrLayer zone: "DrLy'
  static bool readSdrLayer(StarZone &zone);
  //! try to read a SdrLayerSet zone: "DrLS'
  static bool readSdrLayerSet(StarZone &zone);
  //! try to read a object zone: "DrOb'
  static bool readSdrObject(StarZone &zone, StarObject &doc);
  //! try to read a Page/MasterPage zone: "DrPg'
  static bool readSdrPage(StarZone &zone, StarObject &doc);
  //! try to read a Master Page descriptor zone: "DrMP'
  static bool readSdrMPageDesc(StarZone &zone);
  //! try to read a list of Master Page zone: "DrML'
  static bool readSdrMPageDescList(StarZone &zone);

  //! try to read a SdCustomShow
  static bool readSdrCustomShow(StarZone &zone);
  //! try to read a SdrFrameView
  static bool readSdrFrameView(StarZone &zone);
  //! try to read a SdrView
  static bool readSdrView(StarZone &zone);
  //! try to read a SdrHelpLine
  static bool readSdrHelpLine(StarZone &zone);
  //! try to read a SdrHelpLine list
  static bool readSdrHelpLineSet(StarZone &zone);

  //! try to read the presentation data
  static bool readPresentationData(StarZone &zone);

  //! try to read a zone which appear at end of a zone: "DrPg'
  static bool readSdrPageUnknownZone1(StarZone &zone, long lastPos);

  //! try to read a SVDr object
  static bool readSVDRObject(StarZone &zone, int identifier, StarObject &doc);
  //! try to read the first zone of SVDr object
  static bool readSVDRObjectHeader(StarZone &zone);
  //! try to read the object attrib zone
  static bool readSVDRObjectAttrib(StarZone &zone, StarObject &doc);
  //! try to read the object text zone
  static bool readSVDRObjectText(StarZone &zone, StarObject &doc);
  //! try to read the object rect zone
  static bool readSVDRObjectRect(StarZone &zone, StarObject &doc, int identifier);
  //! try to read the object caption zone
  static bool readSVDRObjectCaption(StarZone &zone, StarObject &doc);
  //! try to read the object circle zone
  static bool readSVDRObjectCircle(StarZone &zone, StarObject &doc, int identifier);
  //! try to read the object edge zone
  static bool readSVDRObjectEdge(StarZone &zone, StarObject &doc);
  //! try to read the object graph zone
  static bool readSVDRObjectGraph(StarZone &zone, StarObject &doc);
  //! try to read the object group zone
  static bool readSVDRObjectGroup(StarZone &zone, StarObject &doc);
  //! try to read the object measure zone
  static bool readSVDRObjectMeasure(StarZone &zone, StarObject &doc);
  //! try to read the object OLE zone
  static bool readSVDRObjectOLE(StarZone &zone, StarObject &doc, int identifier);
  //! try to read the object path zone
  static bool readSVDRObjectPath(StarZone &zone, StarObject &doc, int identifier);

  //! try to read a SDR gluepoint
  static bool readSDRGluePoint(StarZone &zone);
  //! try to read a SDR gluepoint list
  static bool readSDRGluePointList(StarZone &zone);
  //! try to read a SDR object connection
  static bool readSDRObjectConnection(StarZone &zone);
  //! try to read a SDR object surrogate
  static bool readSDRObjectSurrogate(StarZone &zone);
  //! try to read a outliner para object
  static bool readSDROutlinerParaObject(StarZone &zone, StarObject &doc);
  //! try to read a SDR userData
  static bool readSDRUserData(StarZone &zone, bool inRecord);
  //! try to read a SDR userData list
  static bool readSDRUserDataList(StarZone &zone, bool inRecord);

protected:
  //
  // data
  //

  //! the state
  shared_ptr<StarObjectDrawInternal::State> m_state;
};
#endif
// vim: set filetype=cpp tabstop=2 shiftwidth=2 cindent autoindent smartindent noexpandtab:
