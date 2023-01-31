 #ifndef MASKPATH_H
 #define MASKPATH_H

#include <QPainterPath>

namespace MaskPath {
    static inline QPainterPath DrawMask(QRect rect, int radius = 0, int inlineWeight = 0) {

        rect.adjust(inlineWeight,inlineWeight,-inlineWeight,-inlineWeight);
        int trigangleWidth = rect.width()/5;
        QPainterPath topTriangle;
        if(radius != 0) radius = radius/2;
        topTriangle.addRoundedRect(QRect(0,0,trigangleWidth,trigangleWidth), radius, radius);

    //	qreal hip = sqrt((trigangleWidth * trigangleWidth) + (trigangleWidth * trigangleWidth));
        qreal hip = sqrt(pow(trigangleWidth,2) + pow(trigangleWidth,2));
        int location = rect.width()/2 - hip/2;
        topTriangle = QTransform()
                     .translate(location,(trigangleWidth/2 + trigangleWidth/5))
                     .rotate(-45)
                     .map(topTriangle);

        QPainterPath mainRect;
        mainRect.addRoundedRect(rect.adjusted(0,trigangleWidth/2,0,0), radius, radius);

        return mainRect + topTriangle;
    }

}



  #endif // MASKPATH_H
