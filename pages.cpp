#include "pages.h"


void PagesIndexBuild(String &page)
{
    page = "<html><body><h1>Index Page</h1></body></html>";
}

void PagesNotFoundBuild(String &page)
{
    page = "<html><body><h1>404<br>Not Found</h1></body></html>";
}