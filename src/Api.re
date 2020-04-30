type users_info = Js.t({
  .
  page: int,
  results: int,
  seed: string,
  version: string,
})
type users_result = Js.t({
  .
  cell: string,
  // dob: {date: "1963-05-16T01:56:25.170Z", age: 57}
  // email: "jeffery.walters@example.com"
  gender: string,
  // id: {name: "TFN", value: "656148633"}
  // location: {street: {…}, city: "Geelong", state: "South Australia", country: "Australia", postcode: 6059, …}
  login: Js.t({
    .
    uuid: string
  }),
  // login: {uuid: "7e21368c-1f6a-4719-a5e9-75b2e9413068", username: "tinymeercat505", password: "erection", salt: "g0xODhMy", md5: "1cb7ef054b61a1ed3e50feeb8803a01e", …}
  name: Js.t({.
    title: string,
    first: string,
    last: string,
  }),
  // nat: "AU"
  phone: string
  // picture: {large: "https://randomuser.me/api/portraits/men/13.jpg", medium: "https://randomuser.me/api/portraits/med/men/13.jpg", thumbnail: "https://randomuser.me/api/portraits/thumb/men/13.jpg"}
  // registered: {date: "2014-06-30T00:38:44.936Z", age: 6
})
type users_response = Js.t({
  .
  info: users_info,
  results: array(users_result)
})

module Async = {
  let let_ = (prom, cb) => Js.Promise.then_(cb, prom);
}

module Api = {
  // type users_response;
  let users = (): Js.Promise.t(users_response) => {
    let%Async res = Axios.get("https://randomuser.me/api?results=20");
    // Js.log(res);
    // "https://randomuser.me/api?results=20"
    // Js.Promise.t(["sdf", "kmmm"]);
    res##data

  }
};