Python 3.9.5 (tags/v3.9.5:0a7dcbd, May  3 2021, 17:27:52) [MSC v.1928 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> response = stub.PostModelOutputs(
    service_pb2.PostModelOutputsRequest(
        model_id="{THE_MODEL_ID}",
        inputs=[
            resources_pb2.Input(
                data=resources_pb2.Data(
                    image=resources_pb2.Image(
                        url="https://samples.clarifai.com/metro-north.jpg"
                    )
                )
            )
        ]
    ),
    metadata=metadata
)
print("Predicted concepts:")
for concept in response.outputs[0].data.concepts:
    print(concept.name + " " + str(concept.value))
