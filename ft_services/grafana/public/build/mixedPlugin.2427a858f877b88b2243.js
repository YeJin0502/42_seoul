(window.webpackJsonp=window.webpackJsonp||[]).push([[59],{CaV2:function(t,e,r){"use strict";r.r(e);var n=r("BkRI"),o=r.n(n),a=r("bt/X"),u=r.n(a),c=r("F/XL"),i=r("0/uQ"),f=r("VNr4"),s=r("psW0"),b=r("67Y/"),p=r("Zn8D"),l=r("Obii"),y=r("t8hP");function O(t){return(O="function"==typeof Symbol&&"symbol"==typeof Symbol.iterator?function(t){return typeof t}:function(t){return t&&"function"==typeof Symbol&&t.constructor===Symbol&&t!==Symbol.prototype?"symbol":typeof t})(t)}function d(t,e){var r=Object.keys(t);if(Object.getOwnPropertySymbols){var n=Object.getOwnPropertySymbols(t);e&&(n=n.filter((function(e){return Object.getOwnPropertyDescriptor(t,e).enumerable}))),r.push.apply(r,n)}return r}function j(t,e,r){return e in t?Object.defineProperty(t,e,{value:r,enumerable:!0,configurable:!0,writable:!0}):t[e]=r,t}function g(t,e){for(var r=0;r<e.length;r++){var n=e[r];n.enumerable=n.enumerable||!1,n.configurable=!0,"value"in n&&(n.writable=!0),Object.defineProperty(t,n.key,n)}}function v(t,e){return!e||"object"!==O(e)&&"function"!=typeof e?function(t){if(void 0===t)throw new ReferenceError("this hasn't been initialised - super() hasn't been called");return t}(t):e}function h(t){return(h=Object.setPrototypeOf?Object.getPrototypeOf:function(t){return t.__proto__||Object.getPrototypeOf(t)})(t)}function w(t,e){return(w=Object.setPrototypeOf||function(t,e){return t.__proto__=e,t})(t,e)}var m=function(t){function e(t){return function(t,e){if(!(t instanceof e))throw new TypeError("Cannot call a class as a function")}(this,e),v(this,h(e).call(this,t))}var r,n,a;return function(t,e){if("function"!=typeof e&&null!==e)throw new TypeError("Super expression must either be null or a function");t.prototype=Object.create(e&&e.prototype,{constructor:{value:t,writable:!0,configurable:!0}}),e&&w(t,e)}(e,t),r=e,(n=[{key:"query",value:function(t){var e=t.targets.filter((function(t){return"-- Mixed --"!==t.datasource}));if(!e.length)return Object(c.a)({data:[]});var r=u()(e,"datasource"),n=[];for(var o in r){var a=r[o],i=a[0].datasource;n.push({datasource:Object(y.getDataSourceSrv)().get(i),targets:a})}return this.batchQueries(n,t)}},{key:"batchQueries",value:function(t,e){var r=t.filter(this.isQueryable).map((function(t,r){return Object(i.a)(t.datasource).pipe(Object(s.b)((function(n){var a=o()(e);return a.requestId="mixed-".concat(r,"-").concat(a.requestId||""),a.targets=t.targets,Object(i.a)(n.query(a)).pipe(Object(b.a)((function(t){return function(t){for(var e=1;e<arguments.length;e++){var r=null!=arguments[e]?arguments[e]:{};e%2?d(Object(r),!0).forEach((function(e){j(t,e,r[e])})):Object.getOwnPropertyDescriptors?Object.defineProperties(t,Object.getOwnPropertyDescriptors(r)):d(Object(r)).forEach((function(e){Object.defineProperty(t,e,Object.getOwnPropertyDescriptor(r,e))}))}return t}({},t,{data:t.data||[],state:l.LoadingState.Loading,key:"mixed-".concat(r,"-").concat(t.key||"")})})))})))}));return Object(f.a)(r).pipe(Object(b.a)(this.markAsDone),Object(p.a)())}},{key:"testDatasource",value:function(){return Promise.resolve({})}},{key:"isQueryable",value:function(t){return t&&Array.isArray(t.targets)&&t.targets.length>0}},{key:"markAsDone",value:function(t){var e=t.length;return 0===e?t:(t[e-1].state=l.LoadingState.Done,t)}}])&&g(r.prototype,n),a&&g(r,a),e}(l.DataSourceApi);r.d(e,"MixedDatasource",(function(){return m})),r.d(e,"Datasource",(function(){return m}))}}]);
//# sourceMappingURL=mixedPlugin.2427a858f877b88b2243.js.map