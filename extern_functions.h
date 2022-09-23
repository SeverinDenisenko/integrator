//
// Created by Severin on 23.09.2022.
//

#ifndef INTEGRATOR_EXTERN_FUNCTIONS_H
#define INTEGRATOR_EXTERN_FUNCTIONS_H

extern double cos_f_(double *value);
extern double sin_f_(double *value);
extern double log_f_(double *value, double *base);

extern double rectangle_(void *function, double *low_lim, double *high_lim, int *steps);
extern double trapezium_(double *value, double *low_lim, double *high_lim, int *steps);
extern double simpson_(double *value, double *low_lim, double *high_lim, int *steps);

#endif //INTEGRATOR_EXTERN_FUNCTIONS_H
