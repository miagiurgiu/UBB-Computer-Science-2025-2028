#ifndef UI_DYNAMIC_H
#define UI_DYNAMIC_H

#include "../service/service_dynamic.h"

typedef struct {
    Service* service; // in the structure of UI keep a pointer to Service
} UI; // the structure receives the name UI

UI create_ui(Service* service); // declaration of a function that creates an UI and receives a pointer to service
void run(UI* ui); // function that runs the app
#endif