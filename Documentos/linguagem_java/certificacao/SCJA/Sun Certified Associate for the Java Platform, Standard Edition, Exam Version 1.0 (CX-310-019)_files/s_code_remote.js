/* SiteCatalyst code version: H.14. Copyright Omniture, Inc. More info available at http://www.omniture.com */
/* Owner: Neil Evans */
/************************** CONFIG SECTION ****************************************/
/* Specify the Report Suite(s) */
var s_account="devsuncom";
var loc=window.top.location.href.toLowerCase();
var first_split = loc.split("//");
var path = first_split[1];
var dir = path.split("/");
if (dir[1]=="aboutsun" && dir[2]=="sunfederal")
{ 
var sun_accountList="sunglobal,suncom,sunfederal=www.sun.com;devsuncom=.";
var s_siteid="sunfederal:";
}
else 
{ 
sun_accountList="sunglobal,suncom=www.sun.com;devsuncom=."; 
s_siteid="sun:";
}

var sun_dynamicAccountSelection=true;
var sun_dynamicAccountList=sun_accountList;

/* Site Settings */
var ltv="prop15,prop16";
if (typeof s_pageName=='undefined') { var s_pageName=""; }
if (typeof s_pageType=='undefined') { var s_pageType=""; }
/* Remote Omniture JS call  */
var sun_ssl=(window.location.protocol.toLowerCase().indexOf("https")!=-1);
	if(sun_ssl == true) { var fullURL = "https://www.sun.com/share/metrics/metrics_group1.js"; }
		else { var fullURL= "http://www-cdn.sun.com/share/metrics/metrics_group1.js"; }
document.write("<sc" + "ript type=\"text/javascript\" src=\""+fullURL+"\"></sc" + "ript>");
/************************** END CONFIG SECTION **************************************/
function s_resetstandard(s) {
	if (typeof s_pageName!='undefined' && s_pageName) {
	s.prop10=s_pageName;
	}
}
n_dynamicAccountList=sun_accountList;

/* Site Settings */
var ltv="prop15,prop16";
if (typeof s_pageName=='undefined') { var s_pageName=""; }
if (typeof s_pageType=='undefined') { var s_pageType=""; }
/* Remote Omniture JS call  */
var sun_ssl=(window.location.protocol.toLowerCase().indexOf("https")!=-1);
	if(sun_ssl == true) { var fullURL = "https://www.sun.com/share/metrics/metrics_group1.js"; }
		else { var fullURL= "http://www-cdn.sun.com/share/metrics/metrics_group1.js"; }
document.write("<sc" + "ript type=\"text/javascript\" src=\""+fullURL+"\"></sc" + "ript>");
/************************** END CONFIG SECTION **************************************/
function s_resetstandard(s) {
	if (typeof s_pageName!='undefined' && s_pageName) {
	s.prop10=s_pageName;
	}
}
