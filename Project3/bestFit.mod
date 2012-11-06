/* Decision variables */

var a; var b; var c; var t;

/* Objective function */
minimize z: t;

/* Constraints */

/*s.t. point_y_high : 19-3+a <= t;
s.t. point_y_low : 19-3+a >= -t;*/

/* For each point make sure b is set right
 * without this a=b=c=t=0
 */
s.t. point_x_1_high : 1  - b <=  t;
s.t. point_x_1_low  : 1  - b >= -t;
s.t. point_x_2_high : 2  - b <=  t;
s.t. point_x_2_low  : 2  - b >= -t;
s.t. point_x_3_high : 3  - b <=  t;
s.t. point_x_3_low  : 3  - b >= -t;
s.t. point_x_4_high : 5  - b <=  t;
s.t. point_x_4_low  : 5  - b >= -t;
s.t. point_x_5_high : 7  - b <=  t;
s.t. point_x_5_low  : 7  - b >= -t;
s.t. point_x_6_high : 8  - b <=  t;
s.t. point_x_6_low  : 8  - b >= -t;
s.t. point_x_7_high : 10 - b <=  t;
s.t. point_x_7_low  : 10 - b >= -t;

/* minimizes the maximum absolute deviation */
s.t. point_1_high : a*(1)  + b*(3)  - c <=  t;
s.t. point_1_low  : a*(1)  + b*(3)  - c >= -t;
s.t. point_2_high : a*(2)  + b*(5)  - c <=  t;
s.t. point_2_low  : a*(2)  + b*(5)  - c >= -t;
s.t. point_3_high : a*(3)  + b*(7)  - c <=  t;
s.t. point_3_low  : a*(3)  + b*(7)  - c >= -t;
s.t. point_4_high : a*(5)  + b*(11) - c <=  t;
s.t. point_4_low  : a*(5)  + b*(11) - c >= -t;
s.t. point_5_high : a*(7)  + b*(14) - c <=  t;
s.t. point_5_low  : a*(7)  + b*(14) - c >= -t;
s.t. point_6_high : a*(8)  + b*(15) - c <=  t;
s.t. point_6_low  : a*(8)  + b*(15) - c >= -t;
s.t. point_7_high : a*(10) + b*(19) - c <=  t;
s.t. point_7_low  : a*(10) + b*(19) - c >= -t;

end
