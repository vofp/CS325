Problem:    bestFit
Rows:       19
Columns:    4
Non-zeros:  65
Status:     OPTIMAL
Objective:  z = 13.09090909 (MINimum)

   No.   Row name   St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 z            B        13.0909                             
     2 slope_x_high B       -13.0909                          -9 
     3 slope_x_low  B        13.0909            -9               
     4 slope_y_high NU           -16                         -16     -0.818182 
     5 slope_y_low  B        10.1818           -16               
     6 point_high_1 B       -26.1818                          -0 
     7 point_low_1  NL             0            -0                   0.0909091 
     8 point_high_2 B       -23.2727                          -0 
     9 point_low_2  B        2.90909            -0               
    10 point_high_3 B       -20.3636                          -0 
    11 point_low_3  B        5.81818            -0               
    12 point_high_4 B       -14.5455                          -0 
    13 point_low_4  B        11.6364            -0               
    14 point_high_5 B       -8.72727                          -0 
    15 point_low_5  B        17.4545            -0               
    16 point_high_6 B       -5.81818                          -0 
    17 point_low_6  B        20.3636            -0               
    18 point_high_7 NU             0                          -0    -0.0909091 
    19 point_low_7  B        26.1818            -0               

   No. Column name  St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 a            B        2.90909             0               
     2 b            NL             0             0                     1.45455 
     3 c            B             16             0               
     4 t            B        13.0909                             

Karush-Kuhn-Tucker optimality conditions:

KKT.PE: max.abs.err = 3.55e-15 on row 6
        max.rel.err = 6.54e-17 on row 5
        High quality

KKT.PB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

KKT.DE: max.abs.err = 0.00e+00 on column 0
        max.rel.err = 0.00e+00 on column 0
        High quality

KKT.DB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

End of output
