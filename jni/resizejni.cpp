#include <resizejni.h>
#include <jni.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <vector>

using namespace cv;
using namespace std;

JNIEXPORT jintArray JNICALL Java_com_jni_ImgDealJni_ResizeMat(JNIEnv* env, jclass obj, jintArray buf, jint w, jint h)
{
				jint *cbuf;
				uchar *r ;
				cbuf = env->GetIntArrayElements(buf , false);
				if(cbuf == NULL){
					return 0;
				}
				Mat imgData(h , w, CV_8UC4 , (unsigned char*)cbuf);
				Size s(100 , 100) ;
				Mat resultMat(100 , 100 , CV_8UC4) ;
				resize(imgData , resultMat , s) ;
				r = resultMat.data ;
				int size = 100 * 100 ;
				jintArray result = env->NewIntArray(size);
				env->SetIntArrayRegion(result , 0 , size , (jint *)r);
				env->ReleaseIntArrayElements(buf, cbuf, 0);

				return result;
}
                                                                                                                                
