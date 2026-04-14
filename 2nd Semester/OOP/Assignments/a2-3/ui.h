#ifndef UI_H // checks if UI_H is not already included
#define UI_H // defines the symbol
// include guards

#include "../service/service_static.h"

typedef struct {
    Service* service; // in the structure of UI keep a pointer to Service
} UI; // the structure receives the name UI

UI create_ui(Service* service); // declaration of a function that creates an UI and receives a pointer to service
void run(UI* ui); // function that runs the app

#endif // end the #ifndef 