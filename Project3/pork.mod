/* Decision variables */

var ham_f >=0;      /* ham */
var ham_r >=0;      /* ham */
var ham_o >=0;      /* ham */

var bellies_f >=0;  /* bellies */
var bellies_r >=0;  /* bellies */
var bellies_o >=0;  /* bellies */

var picnics_f >=0;  /* picnics */
var picnics_r >=0;  /* picnics */
var picnics_o >=0;  /* picnics */


/* Objective function */
maximize z: 8 * ham_f + 12 * ham_r + 11 * ham_o + 4 * bellies_f + 12 * bellies_r + 7 * bellies_o + 4 * picnics_f + 13 * picnics_r + 9 * picnics_o;


/* Constraints */

s.t. Ham            : ham_f + ham_r + ham_o <= 480;
s.t. Bellies        : bellies_f + bellies_r + bellies_o <= 400;
s.t. Picnics        : picnics_f + picnics_r + picnics_o <= 230;
s.t. Smoke_Regular  : ham_r + bellies_r + picnics_r <= 420;
s.t. Smoke_Overtime : ham_o + bellies_o + picnics_o <= 250;

end;
