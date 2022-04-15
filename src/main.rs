use droplet::run;

#[tokio::main]
async fn main() {
    pollster::block_on(run());
}
