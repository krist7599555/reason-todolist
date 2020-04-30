open Api;

module Async = {
  let let_ = (prom, cb) => Js.Promise.then_(cb, prom);
}

[@react.component]
let make = () => {
  let (users, setUsers) = React.useState(() => None);
  React.useEffect0(() => {
    Api.users()
      |> Js.Promise.then_((data: users_response) => {
        Js.log(data);
        setUsers(_ => Some(data##results));
        Js.Promise.resolve()
      })
      |> ignore;
    Some(() => {
      Js.log("OK");
    });
  });

  <main>
    {
      switch users {
      | None => <div>("Nonthing" |> React.string)</div>
      | Some(usrs) => usrs
        |> Array.map((u: users_result) => 
          <div className="pt-1" key=(u##login##uuid)>
            <label>{(u##name##first ++ " " ++ u##name##last) |> React.string}</label>
            <p>{React.string("[gender] " ++ u##gender)}</p>
            <hr/>
          </div>)
        |> React.array
      }
    }
  </main>
};
