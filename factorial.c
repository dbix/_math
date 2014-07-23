//
//  factorial.h
//  Numerics
//
//  Created by Derek Bixler on 7/21/14.
//  Copyright (c) 2014 Derek Bixler. All rights reserved.
//

#include "numerics.h"

const double fact_table[] = {
    1,
    1,
    2,
    6,
    24,
    120,
    720,
    5040,
    40320,
    362880,
    3628800,
    39916800,
    479001600,
    6227020800,
    87178291200,
    1307674368000,
    20922789888000,
    355687428096000,
    6402373705728000,
    121645100408832000,
    2432902008176640000,
    51090942171709440000,
    1124000727777607680000,
    25852016738884978212864,
    620448401733239409999872,
    15511210043330986055303168,
    403291461126605650322784256,
    10888869450418351940239884288,
    304888344611713871918902804480,
    8841761993739701898620088352768,
    2.6525285981219106821760171900928e+32,
    8.2228386541779224301985099289723e+33,
    2.6313083693369351776635231772711e+35,
    8.6833176188118859387156738953183e+36,
    2.9523279903960415733408153396316e+38,
    1.0333147966386145431134989962796e+40,
    3.7199332678990125486367275249474e+41,
    1.3763753091226345578872114833606e+43,
    5.2302261746660111714185989225247e+44,
    2.0397882081197444123129673397697e+46,
    8.1591528324789768379554852130119e+47,
    3.3452526613163807956284472299189e+49,
    1.4050061177528799549331352707053e+51,
    6.0415263063373834074440829285579e+52,
    2.6582715747884488694165799490347e+54,
    1.1962222086548018857499272315747e+56,
    5.5026221598120891535672378899249e+57,
    2.58623241511168177673491006653e+59,
    1.2413915592536072528327568319344e+61,
    6.0828186403426752248860160811673e+62,
    3.0414093201713375576366966406748e+64,
    1.5511187532873821894707545826858e+66,
    8.0658175170943876845634591553352e+67,
    4.2748832840600254847912547653424e+69,
    2.3084369733924137924371883906027e+71,
    1.2696403353658276446882823840816e+73,
    7.109985878048634810254381350857e+74,
    4.0526919504877214099803979753848e+76,
    2.3505613312828784949216569501547e+78,
    1.3868311854568983860514826800456e+80,
    8.3209871127413898950597294060447e+81,
    5.0758021387722483583354016137309e+83,
    3.1469973260387939390320343330721e+85,
    1.9826083154044400849657327747675e+87,
    1.2688693218588416543780689758512e+89,
    8.247650592082471516735380327295e+90,
    5.4434493907744306944549606027564e+92,
    3.6471110918188683221214362054827e+94,
    2.4800355424368305479709011539871e+96,
    1.7112245242814129737573543427207e+98,
    1.1978571669969892212594746686288e+100,
    8.5047858856786230047017360130894e+101,
    6.1234458376886084639206026474671e+103,
    4.4701154615126843855485062791222e+105,
    3.3078854415193862416022970131018e+107,
    2.4809140811395399745349033519924e+109,
    1.8854947016660503806465265475142e+111,
    1.4518309202828587210082629792552e+113,
    1.1324281178206296793535918547746e+115,
    8.9461821307829757136262887790365e+116,
    7.1569457046263805709010310232292e+118,
    5.7971260207473678413578235993885e+120,
    4.7536433370128420198081800698107e+122,
    3.9455239697206587883704426039241e+124,
    3.3142401345653531943477651653896e+126,
    2.817104114380550131023834223967e+128,
    2.4227095383672734128129665067102e+130,
    2.1077572983795278543715285371899e+132,
    1.8548264225739843605432413185723e+134,
    1.6507955160908460243967686903783e+136,
    1.4857159644817615149180874324691e+138,
    1.3520015276784029157751425284733e+140,
    1.2438414054641308178973935344383e+142,
    1.1567725070816415658755923012576e+144,
    1.0873661566567430753888938808332e+146,
    1.0329978488239059304919922079781e+148,
    9.9167793487094964784489225118358e+149,
    9.619275968248212038369657521235e+151,
    9.4268904488832479836729777904857e+153,
    9.3326215443944153252083631296925e+155,
    9.3326215443944150965646704795954e+157,
    9.4259477598383598816354914673273e+159,
    9.6144667150351270792682012966738e+161,
    9.9029007164861804720832421731047e+163,
    1.0299016745145628100140397847047e+166,
    1.081396758240290976701866637109e+168,
    1.1462805637347083682649389856226e+170,
    1.226520203196138004993154848398e+172,
    1.3246418194518290179334165957474e+174,
    1.4438595832024936624984528579916e+176,
    1.5882455415227430287482981437908e+178,
    1.7629525510902445873527557113318e+180,
    1.9745068572210740115452900064873e+182,
    2.231192748659813765724544204963e+184,
    2.5435597334721876551863561454424e+186,
    2.9250936934930159966911857181216e+188,
    3.3931086844518980862340126341225e+190,
    3.9699371608087210616475629732184e+192,
    4.6845258497542909236586970187663e+194,
    5.5745857612076058231040010224919e+196,
    6.689502913449127120509299431182e+198,
    8.0942985252734440920080085764491e+200,
    9.8750442008336010580046091933691e+202,
    1.2146304367025329301345669307844e+205,
    1.5061417415111409313880481383995e+207,
    1.8826771768889261129076032247497e+209,
    2.372173242880046851164245145816e+211,
    3.0126600184576594308995034485094e+213,
    3.8562048236258040715513644140921e+215,
    4.9745042224772874589728997625354e+217,
    6.4668554892204741473620342717715e+219,
    8.4715806908788206313986138847088e+221,
    1.1182486511960043297656813657264e+224,
    1.4872707060906857133840633124847e+226,
    1.992942746161518792813014020149e+228,
    2.6904727073180504073289256741018e+230,
    3.6590428819525488642227787162652e+232,
    5.0128887482749919605321636305893e+234,
    6.9177864726194885807727805587682e+236,
    9.6157231969410893531952816733452e+238,
    1.3462012475717525742234420135339e+241,
    1.8981437590761708897983991170022e+243,
    2.6953641378881628530300954351945e+245,
    3.8543707171800730787494170483564e+247,
    5.5502938327393044385098972916703e+249,
    8.0479260574719917061017005806294e+251,
    1.1749972043909107097291042410969e+254,
    1.7272458904546389230256097456272e+256,
    2.5563239178728653927014405713729e+258,
    3.8089226376305697893300731259235e+260,
    5.7133839564458546839951096888853e+262,
    8.627209774233239985511343864617e+264,
    1.3113358856834524491588203489468e+267,
    2.0063439050956822953263537169266e+269,
    3.0897696138473507758593173815926e+271,
    4.7891429014633940779577833817036e+273,
    7.4710629262828942234753357867367e+275,
    1.1729568794264144742677104957876e+278,
    1.8532718694937349890004524708112e+280,
    2.9467022724950384027683772446534e+282,
    4.7147236359920616095214445713409e+284,
    7.5907050539472189932190765839843e+286,
    1.229694218739449417732502919411e+289,
    2.0044015765453026266402837422488e+291,
    3.2872185855342959088410496156079e+293,
    5.4239106661315886750266819688786e+295,
    9.0036917057784375454334676186055e+297,
    1.5036165148649991455999664759445e+300,
    2.5260757449731984218543204657197e+302,
    4.2690680090047051083347677305819e+304,
    7.2574156153079990350004095523891e+306
};

uint64_t __factorial__(int n) {
    /* Calculate n! from table */
    if (n <= 170)
        return fact_table[n];
    else
        return 1.0/0.0;
}

double __lnfactorial__(int n) {
    /* Natural logarithm of n! */
    return log(fact_table[n]);
}

double __binom_coeff__(int k, int n) {
    /* Binomial coefficient function, a.k.a. "n choose k" */
    if (n < 0 || k < 0 || k < n)
        return NAN;
    else
        return __factorial__(n) / (__factorial__(k) * __factorial__(n - k));
}