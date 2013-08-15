
/* - formsubmithelpers.js - */
// http://www.cybershark.net/portal_javascripts/formsubmithelpers.js?original=1
function inputSubmitOnClick(event){if(!event) var event=window.event;if(hasClassName(this,'submitting')){return confirm(window.form_resubmit_message)} else{addClassName(this,'submitting')}
return true}
function registerSubmitHandler(){var nodes=cssQuery('input[type=submit]');for(var i=0;i<nodes.length;i++){var node=nodes[i];if(!node.onclick){node.onclick=inputSubmitOnClick}}}
registerPloneFunction(registerSubmitHandler);
