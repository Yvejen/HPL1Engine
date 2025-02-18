/*
 * Copyright (C) 2006-2010 - Frictional Games
 *
 * This file is part of HPL1 Engine.
 *
 * HPL1 Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HPL1 Engine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HPL1 Engine.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef HPL_GRAPHICSTYPES_H
#define HPL_GRAPHICSTYPES_H

#include <list>
#include <vector>
#include "graphics/Color.h"
#include "math/MathTypes.h"

namespace hpl {

	#define MAX_TEXTUREUNITS (8)
	#define MAX_NUM_OF_LIGHTS (30)

	enum eMatrix
	{
		eMatrix_ModelView,
		eMatrix_Projection,
		eMatrix_Texture,
		eMatrix_LastEnum
	};

	enum eTileRotation
	{
		eTileRotation_0,
		eTileRotation_90,
		eTileRotation_180,
		eTileRotation_270,
		eTileRotation_LastEnum
	};

	enum ePrimitiveType
	{
		ePrimitiveType_Tri,
		ePrimitiveType_Quad,
		ePrimitiveType_LastEnum
	};

	typedef tFlag tAnimTransformFlag;

	#define eAnimTransformFlag_Translate	(0x00000001)
	#define eAnimTransformFlag_Scale		(0x00000002)
	#define eAnimTransformFlag_Rotate		(0x00000004)

	#define klNumOfAnimTransformFlags (3)

	const tAnimTransformFlag kvAnimTransformFlags[] = {eAnimTransformFlag_Translate,
					eAnimTransformFlag_Scale, eAnimTransformFlag_Rotate};

	//-----------------------------------------

	enum eColorDataFormat
	{
		eColorDataFormat_RGB,
		eColorDataFormat_RGBA,
		eColorDataFormat_ALPHA,
		eColorDataFormat_BGR,
		eColorDataFormat_BGRA,
		eColorDataFormat_LastEnum
	};

	//---------------------------------------

	enum eFontAlign
	{
		eFontAlign_Left,
		eFontAlign_Right,
		eFontAlign_Center,
		eFontAlign_LastEnum
	};

	//---------------------------------------

	class cKeyFrame
	{
	public:
		cVector3f trans;
		cVector3f scale;
		cQuaternion rotation;
		float time;
	};

	typedef std::vector<cKeyFrame*> tKeyFramePtrVec;
	typedef tKeyFramePtrVec::iterator tKeyFramePtrVecIt;

	typedef std::vector<cKeyFrame> tKeyFrameVec;
	typedef tKeyFrameVec::iterator tKeyFrameVecIt;

	//---------------------------------------

	enum eAnimationEventType
	{
		eAnimationEventType_PlaySound,
		eAnimationEventType_LastEnum
	};

	//---------------------------------------

	class cVertexBonePair
	{
	public:
		cVertexBonePair(unsigned int aVtx, unsigned int aBone, float aW)
		{
			vtxIdx = aVtx;
			boneIdx = aBone;
			weight = aW;
		}
		cVertexBonePair(){}


		unsigned int vtxIdx;
		unsigned int boneIdx;
		float weight;
	};


	typedef std::vector<cVertexBonePair> tVertexBonePairVec;
	typedef tVertexBonePairVec::iterator tVertexBonePairVecIt;

	//---------------------------------------

	class cVertex
	{
	public:
        // This overload fixes an error with taking addresses of rvalue-cVertex instances
        cVertex* operator&() {return this;}
		cVertex():pos(0),tex(0),col(0){}
		cVertex(const cVector3f &avPos,const cVector3f &avTex,const cColor &aCol )
		{
			pos = avPos;
			tex = avTex;
			col = aCol;
		}

		cVertex(const cVector3f &avPos,const cColor &aCol )
		{
			pos = avPos;
			col = aCol;
		}

		cVector3f pos;
		cVector3f tex;
		cVector3f tan;
		cVector3f norm;
		cColor col;
	};

	typedef std::list<cVertex> tVertexList;
	typedef tVertexList::iterator tVertexListIt;

	typedef std::vector<cVertex> tVertexVec;
	typedef tVertexVec::iterator tVertexVecIt;
}

#endif // HPL_GRAPHICSTYPES_H
