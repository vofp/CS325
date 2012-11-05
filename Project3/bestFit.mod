/* Decision variables */

var a;
var b;
var c;
var t;

/* Objective function */
minimize z: t;


/* Constraints */



s.t. point_high_1 : a*(1)+b*(3)-c <= t;
s.t. point_low_1 : a*(1)+b*(3)-c <= -t;

s.t. point_high_2 : a*(2)+b*(5)-c <= t;
s.t. point_low_2 : a*(2)+b*(5)-c <= -t;

s.t. point_high_3 : a*(3)+b*(7)-c <= t;
s.t. point_low_3 : a*(3)+b*(7)-c <= -t;

s.t. point_high_4 : a*(5)+b*(11)-c <= t;
s.t. point_low_4 : a*(5)+b*(11)-c <= -t;

s.t. point_high_5 : a*(7)+b*(14)-c <= t;
s.t. point_low_5 : a*(7)+b*(14)-c <= -t;

s.t. point_high_6 : a*(8)+b*(15)-c <= t;
s.t. point_low_6 : a*(8)+b*(15)-c <= -t;

s.t. point_high_7 : a*(10)+b*(19)-c <= t;
s.t. point_low_7 : a*(10)+b*(19)-c <= -t;


end;
