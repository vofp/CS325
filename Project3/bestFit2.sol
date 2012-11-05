Problem:    bestFit2
Rows:       29
Columns:    4
Non-zeros:  85
Status:     OPTIMAL
Objective:  z = 4.5 (MINimum)

   No.   Row name   St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 z            B            4.5                             
     2 point_x_high_1
                    B            -10                          -1 
     3 point_x_low_1
                    NL            -1            -1                         0.5 
     4 point_x_high_2
                    B            -10                          -2 
     5 point_x_low_2
                    B             -1            -2               
     6 point_x_high_3
                    B            -10                          -3 
     7 point_x_low_3
                    B             -1            -3               
     8 point_x_high_4
                    B            -10                          -5 
     9 point_x_low_4
                    B             -1            -5               
    10 point_x_high_5
                    B            -10                          -7 
    11 point_x_low_5
                    B             -1            -7               
    12 point_x_high_6
                    B            -10                          -8 
    13 point_x_low_6
                    B             -1            -8               
    14 point_x_high_7
                    NU           -10                         -10          -0.5 
    15 point_x_low_7
                    B             -1           -10               
    16 point_high_1 B           -8.8                          -0 
    17 point_low_1  B            0.2            -0               
    18 point_high_2 B           -6.6                          -0 
    19 point_low_2  B            2.4            -0               
    20 point_high_3 B           -4.4                          -0 
    21 point_low_3  B            4.6            -0               
    22 point_high_4 NU             0                          -0         < eps
    23 point_low_4  B              9            -0               
    24 point_high_5 B           -1.1                          -0 
    25 point_low_5  B            7.9            -0               
    26 point_high_6 B           -4.4                          -0 
    27 point_low_6  B            4.6            -0               
    28 point_high_7 NU             0                          -0         < eps
    29 point_low_7  B              9            -0               

   No. Column name  St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 a            B           -8.8                             
     2 b            B            5.5                             
     3 c            B             12                             
     4 t            B            4.5                             

Karush-Kuhn-Tucker optimality conditions:

KKT.PE: max.abs.err = 1.42e-14 on row 28
        max.rel.err = 1.48e-16 on row 3
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
