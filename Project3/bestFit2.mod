/* Decision variables */

var a;
var b;
var c;
var t;

/* Objective function */
minimize z: t;


/* Constraints */

s.t. point_x_high_1 : 1 - b <= t;
s.t. point_x_low_1 : 1 - b >= -t;
/*s.t. point_y_high_1 : 3 - c - a <= t;
s.t. point_y_low_1 : 3 - c - a >= -t;
*/

s.t. point_x_high_2 : 2 - b <= t;
s.t. point_x_low_2 : 2 - b >= -t;
/*s.t. point_y_high_2 : 5 - c - a <= t;
s.t. point_y_low_2 : 5 - c - a >= -t;
*/

s.t. point_x_high_3 : 3 - b <= t;
s.t. point_x_low_3 : 3 - b >= -t;
/*s.t. point_y_high_3 : 7 - c - a <= t;
s.t. point_y_low_3 : 7 - c - a >= -t;
*/
s.t. point_x_high_4 : 5 - b <= t;
s.t. point_x_low_4 : 5 - b >= -t;
/*s.t. point_y_high_4 : 11- c - a <= t;
s.t. point_y_low_4 : 11- c - a >= -t;
*/
s.t. point_x_high_5 : 7 - b <= t;
s.t. point_x_low_5 : 7 - b >= -t;
/*s.t. point_y_high_5 : 14- c - a <= t;
s.t. point_y_low_5 : 14- c - a >= -t;
*/
s.t. point_x_high_6 : 8 - b <= t;
s.t. point_x_low_6 : 8 - b >= -t;
/*s.t. point_y_high_6 : 15- c - a <= t;
s.t. point_y_low_6 : 15- c - a >= -t;
*/
s.t. point_x_high_7 : 10- b <= t;
s.t. point_x_low_7 : 10- b >= -t;
/*s.t. point_y_high_7 : 19- c - a <= t;
s.t. point_y_low_7 : 19- c - a >= -t;
*/
s.t. point_high_1 : a*(1)+b*(3)-c <= t;
s.t. point_low_1 : a*(1)+b*(3)-c >= -t;

s.t. point_high_2 : a*(2)+b*(5)-c <= t;
s.t. point_low_2 : a*(2)+b*(5)-c >= -t;

s.t. point_high_3 : a*(3)+b*(7)-c <= t;
s.t. point_low_3 : a*(3)+b*(7)-c >= -t;

s.t. point_high_4 : a*(5)+b*(11)-c <= t;
s.t. point_low_4 : a*(5)+b*(11)-c >= -t;

s.t. point_high_5 : a*(7)+b*(14)-c <= t;
s.t. point_low_5 : a*(7)+b*(14)-c >= -t;

s.t. point_high_6 : a*(8)+b*(15)-c <= t;
s.t. point_low_6 : a*(8)+b*(15)-c >= -t;

s.t. point_high_7 : a*(10)+b*(19)-c <= t;
s.t. point_low_7 : a*(10)+b*(19)-c >= -t;

end;
