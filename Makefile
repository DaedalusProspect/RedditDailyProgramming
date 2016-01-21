.PHONY: clean All

All:
	@echo "----------Building project:[ 247 - Debug ]----------"
	@cd "247" && "$(MAKE)" -f  "247.mk"
clean:
	@echo "----------Cleaning project:[ 247 - Debug ]----------"
	@cd "247" && "$(MAKE)" -f  "247.mk" clean
