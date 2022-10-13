#pragma once

#define QVFEATURE_kernel_check_abi              -1
#define QVFEATURE_kernel_check_permission       -1
#define QVFEATURE_kernel_check_output           -1
#define QVFEATURE_kernel_check_filename         -1
#define QVFEATURE_kernel_set_permission         -1

#define QVFEATURE_ui_has_import_qrcode          -1
#define QVFEATURE_ui_has_store_state            -1

#define QVFEATURE_util_has_ntp                  1

#define QV_FEATURE(feat) ((1 / QVFEATURE_##feat) == 1)
