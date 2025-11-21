PROJECT_DIR = $(CURDIR)
PLATFORMIO_BIN = /bin/pio

all: build upload

help: ## Show available Makefile targets
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-10s\033[0m %s\n", $$1, $$2}'

build: ## Build the firmware
	$(PLATFORMIO_BIN) run -d $(PROJECT_DIR)

upload: ## Build and upload the firmware to the device
	$(PLATFORMIO_BIN) run -d $(PROJECT_DIR) -t upload

clean: ## Remove temporary build files
	$(PLATFORMIO_BIN) run -d $(PROJECT_DIR) -t clean

monitor: ## Open the serial monitor
	$(PLATFORMIO_BIN) device monitor

.PHONY: all help build upload clean monitor
