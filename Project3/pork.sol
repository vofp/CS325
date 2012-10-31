Problem:    pork
Rows:       6
Columns:    9
Non-zeros:  24
Status:     OPTIMAL
Objective:  z = 10910 (MAXimum)

   No.   Row name   St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 z            B          10910                             
     2 Ham          NU           480                         480             8 
     3 Bellies      NU           400                         400             5 
     4 Picnics      NU           230                         230             6 
     5 Smoke_Regular
                    NU           420                         420             7 
     6 Smoke_Overtime
                    NU           250                         250             3 

   No. Column name  St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 ham_f        B            440             0               
     2 ham_r        NL             0             0                          -3 
     3 ham_o        B             40             0               
     4 bellies_f    NL             0             0                          -1 
     5 bellies_r    B            400             0               
     6 bellies_o    NL             0             0                          -1 
     7 picnics_f    NL             0             0                          -2 
     8 picnics_r    B             20             0               
     9 picnics_o    B            210             0               

Karush-Kuhn-Tucker optimality conditions:

KKT.PE: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
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
