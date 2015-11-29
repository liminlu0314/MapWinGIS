#pragma once
#include "ogr_feature.h"

class Shape2Ogr
{
public:
	static bool Shapefile2OgrLayer(IShapefile* sf, OGRLayer* poLayer, bool saveLabels, ICallback* callback = NULL);
	static int SaveShapefileChanges(OGRLayer* poLayer, IShapefile* shapefile, long shapeCmnIndex, tkOgrSaveType saveType, bool validateShapes, vector<OgrUpdateError>& errors);
	static bool ShapeRecord2Feature(IShapefile* sf, long shapeIndex, OGRFeature* feature, OGRFeatureDefn* fields, tkOgrSaveType saveType, bool editing, CString& validationError, bool validateShape = false);
	static int RemoveDeletedFeatures(OGRLayer* layer, IShapefile* sf, long shapeCmnIndex);
private:
	static bool ShapefileFieldsToOgr(IShapefile* sf, OGRLayer* poLayer);
	static void ShapesToOgr(IShapefile* sf, OGRLayer* layer, ICallback* callback);
	static void RecreateFieldsFromShapefile(OGRLayer* layer, OGRFeatureDefn* fields, IShapefile* sf);
	static OGRFieldType ShapeFieldType2OgrFieldType(FieldType fieldType);
	static void CopyRecordAttributes(IShapefile* sf, long shapeIndex, OGRFeature* feature, bool editing, OGRFeatureDefn* fields);
	static bool SaveShape(OGRLayer* poLayer, OGRFeature* ft, OGRFeatureDefn* fields, IShapefile* shapefile, int shapeIndex, long shapeCmnIndex, tkOgrSaveType saveType, bool validateShapes, vector<OgrUpdateError>& errors);
	static OGRFeature* GetFeature(OGRLayer* poLayer, IShapefile* shapefile, long shapeCmnIndex, long shapeIndex, long& featId);
};


