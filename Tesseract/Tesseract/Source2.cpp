
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>


using namespace std;

int main(int argc, char *argv[])
{


	tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
	if (api->Init(NULL, "eng")) {
		fprintf(stderr, "Could not initialize tesseract.\n");
		exit(1);
	}
	Pix*image = pixRead("d:/OCR/t440.png ");
	api->SetImage(image);

	Boxa* boxes = api->GetComponentImages(tesseract::RIL_WORD, true, NULL, NULL);
	
		BOX* box = boxaGetBox(boxes, 0, L_CLONE);
	
		char* ocrResult = api->GetUTF8Text();
		
			int conf = api->MeanTextConf();
			fprintf(stdout, "Confidence % % : %d, text: %s", conf, ocrResult);

	printf("OCR output:\n%s", ocrResult);
	

	}

