[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  switch (url.path) {
  | [] => <Home />
  | ["todo"] => <Todo />
  | _ => <NotFound />
  };
};