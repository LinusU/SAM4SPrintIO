// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "SAM4SPrintIO",
    products: [
        .library(name: "SAM4SPrintIO", targets: ["SAM4SPrintIO"]),
    ],
    targets: [
        .binaryTarget(name: "SAM4SPrintIO", path: "SAM4SPrintIO.xcframework"),
    ]
)
